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
#include <time.h>
#include <stdio.h>
#include "fitsio.h"
#include "healpix_map.h"
#include "/home/hong/Desktop/protobuf/proto_new/kdt3.pb.h"
#include "/home/hong/Desktop/protobuf/proto_new/kdt3.pb.cc"
#define MAXN 10000000
#define MAXM 10000000
#define K 2

//#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#define MASTER 0
#define N 4
#define M 5


#include <sys/time.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define SERVER_PORT 9090
#define NUM_MAX 1024

static int NSIDE = 5;
static const double PI =  3.14159265359;
static const Healpix_Map<unsigned long> HB(NSIDE, NEST);

char dianx[20];
char diany[20];

using namespace std;
int id ;  //Record the folder name
int idnum;  //Record the document name
const int k = 2;
int n, m, idx;
int cnt;
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

//calculate healpixid
int healpixid(double RA, double DEC)
{
    pointing *pt = new pointing();

    pt->phi = RA * PI / 180;
    pt->theta = (90-DEC) * PI /180;
    int healpix_ID = HB.ang2pix(*pt);

    delete(pt);
    return healpix_ID;
}


//typedef pair<double, Point> PDP;
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

struct Tree {
    point p[MAXN<<2];
    int son[MAXN<<2];
    int umax;

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

        for( i = 0; i<umax+1; i++)   ///son数组的元素个数与p不同，4×
            ttt.add_son( son[i] );

        //fstream output("/home/hong/Desktop/protoc/450", ios::out | ios::trunc | ios::binary);
        char filename[1000];
        sprintf(filename, "/home/hong/disks/disk2/Catalogue/Processed/2MASS/b_data/b9million/b%d", id);
        
        fstream output(filename, ios::out | ios::trunc | ios::binary);

        if (!ttt.SerializeToOstream(&output))
            cerr << "Failed to write tree." << endl;
    }

    void pb2tree()
    {
        Node tree;
       
        char filename[1000];
        sprintf(filename, "/home/hong/disks/disk2/Catalogue/Processed/2MASS/b_data/b9million/b%d/b%d", id,idnum);

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

///Protobuf to Tree

int main()
{
    //recieve message
    cout << "==========>>>>> START TO SERVE <<<<<==========\n" << endl;
	//initial database

	struct sockaddr_in s_in;					//server address structure
	struct sockaddr_in c_in;					//client address structure
	int l_fd,c_fd;
	socklen_t len;
	char buf[NUM_MAX];							//content buff area

	//memset((void *)&s_in, 0, sizeof(s_in));

	s_in.sin_family = AF_INET;					//IPV4 communication domain
	s_in.sin_addr.s_addr = INADDR_ANY;			//accept any address
	s_in.sin_port = htons(SERVER_PORT);			//change port to netchar

	l_fd = socket(AF_INET, SOCK_STREAM, 0);		//socket(int domain, int type, int protocol)

	bind(l_fd, (struct sockaddr *)&s_in, sizeof(s_in));

	listen(l_fd, NUM_MAX);						//lisiening start

    
    c_fd = accept(l_fd,(struct sockaddr *)&c_in,&len);

    //memset(&buf,0,sizeof(buf));

    read(c_fd, buf, NUM_MAX);
    clock_t startTime, endTime;
    startTime = clock();
    int t=0; int stop=0;
    string reqStr(buf);

    for(int i=0;i<reqStr.length();i++)
    {
        if(stop==0)
        {
            if(reqStr[i]!=' ')
            {
                dianx[t]=reqStr[i];
                t++;
            }
            else
            {
                t=0;
                stop=1;
                continue;
            }
        }
        if(stop==1)
        {
            diany[t]=reqStr[i];
            t++;
        }
    }

    point p;

    p.x[0] = strtod(dianx,NULL);
    p.x[1] = strtod(diany,NULL);

    //cout<<p.x[0]<< " "<<p.x[1]<<endl;
    id = healpixid(p.x[0],p.x[1]);
    cout<<id<<endl;
    idnum=0;

    while(idnum<3)
    {
        kd.pb2tree();
        kd.query(p, 10);

        while(!nq.empty())
        {
            ///nq为优先队列
            PDP tm = nq.top();
            //printf("%lf %lf %lf\n" , tm.dis, tm.p.x[0], tm.p.x[1] );
            nq.pop();
        }
        idnum++;
    }


    endTime = clock();
    cout<<"calculate time："<<(double)(endTime - startTime) / CLOCKS_PER_SEC<<"s"<<endl;

}

///Make Test File
/*
int main()
{
    cnt = 0;
    double x, y, d;
    freopen("/home/hong/disks/disk2/Catalogue/Processed/2MASS/psc_ra_dec_HP_3_HP", "r", stdin);
    freopen("/home/hong/disks/disk2/Catalogue/Processed/2MASS/FileSizeTest/15m", "w", stdout);

    while( scanf("%lf %lf %d", &x, &y, &d) != EOF)
    {
        ++cnt;
        printf("%lf %lf\n", x, y);
        if(cnt == 15000000) break;

    }
    return 0;
}
*/

///Tree to Protobuf

/*int main()
{
    char name[1000];
    int T;
    cnt = 0;

    while(id<414)
    {

        sprintf(name, "/home/hong/disks/disk2/Catalogue/Processed/2MASS/part/%d", id);
        freopen(name, "r", stdin);

        while( scanf("%lf %lf", &po[cnt].x[0], &po[cnt].x[1]) != EOF)
        {
            ++cnt;
        }

        kd.build(0, cnt);

        cout << "UMAX = " << kd.umax << endl;

        kd.tree2pb(cnt);
        id ++;
        cnt = 0;
    }
    //cout<<cnt<<endl;
    return 0;
}*/

///MPI部分
/*
int main()
{

    int rk;
    int sz;
    double result[M*2];
    double finalResult[N*M*2];
    double input[3];

    MPI_Init(0,0);

    MPI_Comm_rank(MPI_COMM_WORLD, &rk);
    MPI_Comm_size(MPI_COMM_WORLD, &sz);

    point p;
    p.x[0] = 267.16616600 ;
    p.x[1] =  -29.95827700;

    MPI_Bcast(input, 3, MPI_DOUBLE, MASTER, MPI_COMM_WORLD);  ///所有一起广播，达到logN复杂度


    //freopen("2.out", "w", stdout);


    kd.pb2tree();
    kd.query(p, 5);

    int k=0;
    while(!nq.empty())
    {
        ///nq为优先队列
        PDP tm = nq.top();

        //printf("%lf %lf %lf\n" , tm.dis, tm.p.x[0], tm.p.x[1] );
        result[k] =  tm.p.x[0];
        result[k+1] = tm.p.x[1];
        k += 2;

        nq.pop();
    }

    MPI_Gather(result, M*2, MPI_DOUBLE, finalResult, M*2, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    MPI_Barrier(MPI_COMM_WORLD);

    if( rk == MASTER )
    {
        for( int i=0; i < N*M*2; i=i+2 )
        {
            printf( "%lf %lf\n", finalResult[i], finalResult[i+1]);
        }
    }

    MPI_Finalize();
}
*/

