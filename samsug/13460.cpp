// BOJ 백준 13460번 구슬 탈출2
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N,M;
char matrix[11][11];
struct myST{
    int rx;
    int ry;
    int bx;
    int by;
    int turn;
};

queue<myST> q;

int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

bool visited[11][11][11][11];

void move(int &x, int &y, int &dist, int &i)
{
    while(matrix[x][y]!='O'&&matrix[x+dx[i]][y+dy[i]]!='#')
    {
        x+=dx[i];
        y+=dy[i];
        dist++;
    }
}

void bfs()
{
    while(!q.empty())
    {
        int rx=q.front().rx;
        int ry=q.front().ry;
        int bx=q.front().bx;
        int by=q.front().by;

        int turn=q.front().turn;

        q.pop();

        for(int i=0;i<4;i++)
        {
            int nrx=rx;
            int nry=ry;
            int nbx=bx;
            int nby=by;
            int rd=0;
            int bd=0;
            int nturn=turn+1;

            if(nturn>10)
                break;

            move(nrx,nry,rd,i);
            move(nbx,nby,bd,i);

            if(matrix[nbx][nby]=='O')
                continue;
            if(matrix[nrx][nry]=='O')
            {
                cout<<nturn;
                return;
            }
            if(nrx==nbx && nry==nby)
            {
                if(rd>bd)
                {
                    nrx-=dx[i];
                    nry-=dy[i];
                }
                else
                {
                    nbx-=dx[i];
                    nby-=dy[i];
                }
            }
            if(visited[nrx][nry][nbx][nby])
                continue;
            visited[nrx][nry][nbx][nby]=1;
            q.push({nrx,nry,nbx,nby,nturn});
        }
    }
    cout<<-1;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //보드 세로 N 가로 M, 빨간 구슬 구멍통해서 빼기
    // 빈칸. 장애물 # 구멍 O 

    cin>>N>>M;

    int rx=0,ry=0,bx=0,by=0;

    // init
    for(int i=0;i<N;i++)
    {
        string s;
        cin>>s;

        for(int j=0;j<M;j++)
        {
            matrix[i][j]=s[j];
            if(s[j]=='R')
            {
                rx=i;
                ry=j;
            }
            else if(s[j]=='B')
            {
                bx=i;
                by=j;
            }
        }
    }

    q.push({rx,ry,bx,by,0});
    visited[rx][ry][bx][by]=1;
    bfs();
    
    return 0;
}
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct myST{
    int rx;
    int ry;
    int bx;
    int by;
    int turn;
};

int N,M;
vector<vector<int>> matrix;
int rx, ry;
int bx, by;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
bool visited[11][11][11][11]={false};

void move(int &x, int &y, int &dist, int &i)
{
    while(matrix[x][y]!='O' && matrix[x+dx[i]][y+dy[i]]!='#')
    {
        x+=dx[i];
        y+=dy[i];
        dist++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N>>M;
    matrix.resize(N+1,vector<int>(M+1));

    // init
    for(int i=1;i<=N;i++)
    {
        string input;
        cin>>input;

        for(int j=1;j<=M;j++)
        {
            matrix[i][j]=input[j-1];

            if(matrix[i][j]=='R')
            {
                rx=i;
                ry=j;
            }

            else if(matrix[i][j]=='B')
            {
                bx=i;
                by=j;
            }
        }
    }

    queue<myST> q;
    int turn=0;
    visited[rx][ry][bx][by]=1;
    q.push({rx,ry,bx,by,turn});

    while(!q.empty())
    {
        int crx=q.front().rx;
        int cry=q.front().ry;
        int cbx=q.front().bx;
        int cby=q.front().by;
        int cturn=q.front().turn;
        q.pop();

        for(int i=0;i<4;i++)
        {
            int nrx=crx;
            int nry=cry;
            int nbx=cbx;
            int nby=cby;
            int bd=0;
            int rd=0;
            int nturn=cturn+1;

            if(nturn>10)
            {
                cout<<-1;
                return 0;
            }
            move(nbx,nby,bd,i);
            move(nrx,nry,rd,i);

            if(matrix[nbx][nby]=='O')
                continue;
            if(matrix[nrx][nry]=='O')
            {
                cout<<nturn;
                return 0;
            }

            if(nrx==nbx && nry==nby)
            {
                if(bd>rd)
                {
                    nbx-=dx[i];
                    nby-=dy[i];
                }
                else
                {
                    nrx-=dx[i];
                    nry-=dy[i];
                }
            }

            if(visited[nrx][nry][nbx][nby])
                continue;
            visited[nrx][nry][nbx][nby]=1;
            q.push({nrx,nry,nbx,nby,nturn});
        }
    }
    // 안되는 경우 -1 안하면 안된다.
    cout<<-1;

    return 0;
}