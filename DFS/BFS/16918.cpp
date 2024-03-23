//BOJ 백준 16918번 봄버맨
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int R,C,N;
int t=0;
vector<vector<char>> map;
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};
vector<pair<int,int>> bomb;
queue<pair<int,int>> q;

void init()
{
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(map[i][j]=='O')
                q.push({i,j});
        }
    }
}

void addBomb()
{
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(map[i][j]=='O')
                continue;
            else
                map[i][j]='O';
        }
    }
}

void explode()
{
    while(!q.empty())
    {
        int cy=q.front().first;
        int cx=q.front().second;
        q.pop();

        for(int i=0;i<4;i++)
        {
            int ny=cy+dy[i];
            int nx=cx+dx[i];
            map[cy][cx]='.';
            if(nx<0 || nx>=C || ny<0 || ny>=R)
                continue;
            if(map[ny][nx]=='O')
                map[ny][nx]='.';
        }
    }
}

void print()
{
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cout<<map[i][j];
        }
        cout<<"\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>R>>C>>N;
    map.resize(R+1,vector<char>(C+1));

    // 초기 폭탄 입력
    for(int i=0;i<R;i++)
    {
        string st;
        cin>>st;
        for(int j=0;j<C;j++)
        {
            map[i][j]=st[j];
            if(map[i][j]=='O')
                q.push({i,j});
        }
    }
    N--;
    if(N==0)
    {
        print();
        return 0;
    }
    while(1)
    {
        //폭탄 설치
        addBomb();
        N--;
        if(N==0)
        {
            print();
            break;
        }
        //폭파
        explode();
        N--;
        if(N==0)
        {
            print();
            break;
        }
        init();
    }
 
   
    return 0;
}