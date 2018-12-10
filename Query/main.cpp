#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <queue>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <unistd.h>
#include <string.h>
#include <set>
#include <map>
#include <time.h>
#include <bitset>
#include <sys/stat.h>
#include <ftw.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "./include/healpix_map.h"
#include "./include/kdt3.pb.h"
#include "kdt3.pb.cc"

#define MAXN 10000000
#define MAXM 10000000
#define K 2
#define MASTER 0
#define N 4
#define M 5
#define SERVER_PORT 9090
#define NUM_MAX 1024
static int NSIDE = 5;
static const double PI =  3.14159265359;
static const Healpix_Map<unsigned long> HB(NSIDE, NEST);

char dianx[20];
char diany[20];
char filepath[200];
//string path;

using namespace std;
int id =0 ;  //record file name
int tmp;
int idnum;  //recod file number
const int k = 2;
int n, m, idx;
int cnt;
string path, coor_x, coor_y;
struct timeval t1,t2;


struct point{
    int id;
    double x[2];
    bool operator < (const point &u) const{
        return x[idx] < u.x[idx];
    }
}po[MAXN];

double pow(double x) {
    return 1.0*x*x;
}
double pow(int x) {
    return 1.0*x*x;
}

/*
 * FUNCTION: calculate healpixid
 */
int healpixid(double RA, double DEC)
{
    pointing *pt = new pointing();

    pt->phi = RA * PI / 180;
    pt->theta = (90-DEC) * PI /180;
    int healpix_ID = HB.ang2pix(*pt);

    delete(pt);
    return healpix_ID;
}


struct PDP{
    double dis;
    point p;
    bool operator < (const PDP pdp) const {
        if(dis != pdp.dis) return dis < pdp.dis;
        else {
            for(int i = 0; i < K; i++)
                if(p.x[i] != pdp.p.x[i]) return p.x[i] < pdp.p.x[i];
            return false;//重复点对结果没影响
        }
    }
    PDP(double _dis, point _p) {
        dis = _dis;
        p = _p;
    }
};

priority_queue<PDP> nq;


/*
 * FUNCTION: struct tree
 */
struct Tree {
    point p[MAXN<<2];
    int son[MAXN<<2];
    int umax;
    char filename[1000];

    Tree()
    {
        umax = 0;
    }

    void build ( int l , int r , int u = 1 , int dep = 0 )
    {
        if(l > r) return;
        son[u] = r-l;
        son[u<<1] = son[u<<1|1] = -1;
        idx = dep%k;
        int mid = (l+r)>>1;
        nth_element(po+l, po+mid, po+r+1);
        p[u] = po[mid];
        if(umax < u<<1) umax = u<<1;
        build ( l , mid-1 , u<<1 , dep+1 );
        build ( mid+1 , r , u<<1|1 , dep+1 );
    }

    void query(point a, int m, int u = 1, int dep = 0){
        if(son[u] == -1) return;

        PDP nd(0, p[u]);
        for(int i = 0; i < k; i++)
            nd.dis += pow( nd.p.x[i] - a.x[i] );

        int dim = dep%k, fg = 0;
        int x = u<<1, y = u<<1|1;

        if(a.x[dim] >= p[u].x[dim])
            swap(x, y);
        if(~son[x])
            query(a, m, x, dep+1);

        if(nq.size() < m) nq.push(nd), fg = 1;
        else
        {
            if(nd.dis < nq.top().dis)
                nq.pop(), nq.push(nd);

            if(pow(a.x[dim] - p[u].x[dim]) < nq.top().dis)
                fg = 1;
        }

        if(~son[y] && fg)
            query(a, m, y, dep+1);
    }

    void tree2pb(int nnn)
    {
        Node ttt;
        int i;
        for( i = 0; i < nnn ; i++)
        {
            ttt.add_x( p[i].x[0] );
            ttt.add_y( p[i].x[1] );
        }
        for( i = 0; i<umax+1; i++)
            ttt.add_son( son[i] );

        ///Change original file path
        sprintf(filename, "%s/b%d", filepath, id);
        fstream output(filename, ios::out | ios::trunc | ios::binary);

        if (!ttt.SerializeToOstream(&output))
            cerr << "Failed to write tree." << endl;
    }

    void pb2tree()
    {
        Node tree;

        ///Change index file path
        sprintf(filename, "%s/b%d", filepath, id);
        //printf("%s\n",filename);
        fstream input(filename, ios::in | ios::binary);
        if (!tree.ParseFromIstream(&input))
            cerr << "Failed to parse tree." << endl;
        int i;
        for( i = 0 ; i<tree.x_size(); i++)
        {
            p[i].x[0] = tree.x(i);
            p[i].x[1] = tree.y(i);
        }
        for( i = 0; i<tree.son_size(); i++)   ///son数组的元素个数与p不同，4×
            son[i] = tree.son(i);
    }
}kd;



/*
 * FUNCTOIN: Query request && return result
 */
int main()
{
    //接受消息
    cout << "==========>>>>> START TO SERVE <<<<<==========\n" << endl;
	//初始化数据库

	struct sockaddr_in s_in;					//server address structure
	struct sockaddr_in c_in;					//client address structure
	int l_fd,c_fd;
	socklen_t len;
	char buf[NUM_MAX];							//content buff area
    memset((void *)&s_in, 0 ,sizeof(s_in));

	s_in.sin_family = AF_INET;					//IPV4 communication domain
	s_in.sin_addr.s_addr = INADDR_ANY;			//accept any address
	s_in.sin_port = htons(SERVER_PORT);			//change port to netchar
	l_fd = socket(AF_INET, SOCK_STREAM, 0);		//socket(int domain, int type, int protocol)
	bind(l_fd, (struct sockaddr *)&s_in, sizeof(s_in));
	listen(l_fd, NUM_MAX);						//lisiening start

	c_fd = accept(l_fd,(struct sockaddr *)&c_in,&len);
    memset(&buf, 0 ,sizeof(buf));
    read(c_fd, buf, NUM_MAX);
    string reqStr(buf);
    gettimeofday(&t1,NULL);
    int i;
    istringstream is (reqStr);
    is>>path>>coor_x>>coor_y;
    for(i=0; i<coor_x.length(); i++)
        dianx[i]=coor_x[i];
    dianx[i] = '\0';
    for(i=0; i<coor_y.length(); i++)
        diany[i]=coor_y[i];
    diany[i] = '\0';
    for(i=0; i<path.length(); i++)
        filepath[i]=path[i];
    filepath[i] = '\0';

    point p;
    p.x[0] = strtod(dianx,NULL);
    p.x[1] = strtod(diany,NULL);
    id = healpixid(p.x[0],p.x[1]);
    kd.pb2tree();
    kd.query(p, 5);

    int tempnum;
    srand(time(0));
    while(!nq.empty())
    {

        PDP tm = nq.top();
        printf("RA = %lf, DEC = %lf, " , tm.p.x[0], tm.p.x[1] );
        tempnum=rand()%(19589-4792+1)+4792;
        printf("%d\n", tempnum);
        nq.pop();
    }
    gettimeofday(&t2,NULL);
    cout<<"Runtime："<<(double)((t2.tv_sec-t1.tv_sec)*1000000+t2.tv_usec-t1.tv_usec)/1000<<"ms"<<endl;
}



/*
 * FUNCTOIN: build grouped spatial index file
 */
/*int main()
{
    char name[1000];
    int T;
    cnt = 0;
    cout<<"--------Start building index file--------"<<endl;

    gettimeofday(&t1,NULL);
    while(id<3982)
    {

        sprintf(name, "/home/hong/disks/disk2/Catalogue/Processed/2MASS/part/%d", id);
        freopen(name, "r", stdin);

        while( scanf("%lf %lf", &po[cnt].x[0], &po[cnt].x[1]) != EOF)
        {
            ++cnt;
        }

        kd.build(0, cnt);
        kd.tree2pb(cnt);
        id ++;
        cnt = 0;
    }
    gettimeofday(&t2,NULL);
    cout<<"--------Build complete--------"<<endl;
    cout<<"运行时间："<<(double)((t2.tv_sec-t1.tv_sec)*1000000+t2.tv_usec-t1.tv_usec)/1000<<"ms"<<endl;
    return 0;
}*/


