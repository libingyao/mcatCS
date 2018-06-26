#include <iostream>
#include <string>
#define MAXN 1000
#define Max 26
using namespace std;

string servers[4][2007];
int counterOfServers[4] ={0,0,0,0};


typedef struct node
{
    struct node *next[Max];
    int num;
    int operation;
    int cflct;
}Node;


//Create new node
Node *createNew()
{
    Node *p=new Node;
    for(int i=0;i<Max;i++)
    {
        p->next[i]=NULL;
    }
    p->num=0;
    return p;
}

//Insert new string
void Insert_str(char str[], Node *head)
{
    int len=strlen(str);
    Node *t,*p=head;
    for(int i=0;i<len;i++)
    {
        int c=str[i]-'0';
        if(p->next[c]==NULL)
        {
            t=createNew();
            p->next[c]=t;
            p->num++;
            //cout<<p->num<<endl;
             p=p->next[c];
        }
        else
        {
            p=p->next[c];
        }
    }
}

int Search_str(char str[],Node *head)
{
    Node *p=head;
    int len=strlen(str);
    int count=0;
    for(int i=0;i<len;i++)
    {
        int c=str[i]-'0';
        if(p->next[c]==NULL)
        {

            cout<<"exist no string"<<endl;
            count=0;
            return 0;
        }
        else
        {
            p=p->next[c];
            count=p->num;
        }
    }
    return count;
}

int PutStringIntoServer(int ServerID, string str)
{
	int total = counterOfServers[ServerID];
	servers[ServerID][total] = str;

	counterOfServers[ServerID]++;
}

int CalComflictBetweenStrings(string str1, string str2)
{
	int len1 = str1.length();
	int len2 = str2.length();

	//compare length
	if(len1 > len2)
	{
		string tem = str2;
		str2 = str1;
		str1 = tem;
	}

	string substr = str2.substr( 0, str1.length() );

	if(substr == str1) return 1;
	return 0;
}

int CalComflictForServer(int ServerID, string str)
{
	int cnt = 0;
	int total = counterOfServers[ServerID];

	if( total == 0 ) return 0;

	for(int i=0; i < total; i++ )
		cnt += CalComflictBetweenStrings(str, servers[ServerID][i]);

	return cnt;
}

void Judge(string str)
{
	int result = -1;
	int mark = -1;
	for(int i=0; i<4; i++)
	{
		if(result == -1)
		{
            result = CalComflictForServer(i, str);
            mark = i;
        }

		else if( result > CalComflictForServer(i, str) )
		{
            result = CalComflictForServer(i, str);
            mark = i;
		}
	}
	PutStringIntoServer(mark, str);
}

double Ex(int ServerID)
{
	int total = counterOfServers[ServerID];
	double totalConflict = 0.0;

	for(int i=0; i<total; i++)
	{
		totalConflict += CalComflictForServer(ServerID, servers[ServerID][i]);
	}

	return totalConflict/total ;
}

int main()
{

        for(int i=0; i<4; i++)
        {
            counterOfServers[i] = 0;
        }

        for(int i=0; i<1000; i++)
        {
            Judge(data[i]);
        }

    /*
    int loop = 2000;

    while(loop--)
    {
        for(int i=0; i<2000; i++)
        {
            Judge(data[i]);
        }

        double sum = 0;
        for(int i=0; i<4; i++)
        {
            sum += Ex(i);
        }
        cout << sum/4 <<endl << endl;

        int cnt = 0;
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<counterOfServers[i]; j++)
            {
                data[cnt] = servers[i][j];
                cnt++;
            }
        }

        for(int i=0; i<4; i++)
        {
            counterOfServers[i] = 0;
        }

    }
    */
    return 0;
}




