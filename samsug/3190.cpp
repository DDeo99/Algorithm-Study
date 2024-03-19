// BOJ 백준 3190번 뱀
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N,K,L;
int t=0;
vector<vector<int>> map;
queue<pair<int,int>> snake;
queue<pair<int,char>> nextD;
int sx,sy;
// 하 우 상 좌
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N;
    cin>>K;
    map.resize(N,vector<int>(N,0));
    sx=0;
    sy=0;
    //뱀은 1
    map[sy][sx]=1;
    snake.push({sy,sx});

    for(int i=0;i<K;i++)
    {
        int x,y;
        cin>>y>>x;
        // 사과는 2
        map[y-1][x-1]=2;
    }

    cin>>L;
    
    for(int i=0;i<L;i++)
    {
        int X;
        char C;
        // X초 후에 방향 왼쪽 L 오른쪽 D으로 회전
        cin>>X>>C;
        nextD.push({X,C});
    }  
    int idx=1;
    while(1)
    {
        sx+=dx[idx];
        sy+=dy[idx];
        t++;
        if(sx<0 || sx>N-1 || sy<0 || sy>N-1)
            break;
        if(map[sy][sx]==1)
            break;
        else if(map[sy][sx]==2)
        {
            map[sy][sx]=1;
            snake.push({sy,sx});
        }
        else if(map[sy][sx]==0)
        {
            map[snake.front().first][snake.front().second]=0;
            snake.pop();
            map[sy][sx]=1;
            snake.push({sy,sx});
        }

        

        if(!nextD.empty())
        {
            if(t==nextD.front().first)
            {
                if(nextD.front().second=='D')
                {
                    idx=(idx+3)%4;
                    nextD.pop();
                }

                else if(nextD.front().second=='L')
                {
                    idx=(idx+1)%4;
                    nextD.pop();
                }
                
            }
        }
    }
    cout<<t;


    return 0;
}
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

queue<pair<int,int>> snake;
queue<pair<int,char>> change;
vector<vector<int>> map;
int N,K,L;

// 상 좌 하 우
// 왼쪽 -> +1  오른쪽 -> +3
int dx[]={0,-1,0,1}; 
int dy[]={-1,0,1,0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N;
    map.resize(N+1,vector<int>(N+1));

    int x=1;
    int y=1;
    snake.push({y,x});
    map[y][x]=1;

    cin>>K;
    for(int i=0;i<K;i++)
    {
        int y,x;
        cin>>y>>x;
        // 사과
        map[y][x]=2;
    }

    cin>>L;
    for(int i=0;i<L;i++)
    {
        int X; char C;
        cin>>X>>C;
        change.push({X,C});
    }

    int ans=0;
    int idx=3;
    while(1)
    {
        y+=dy[idx];
        x+=dx[idx];
        ans++;

        if(y<1 || y>N || x<1 || x>N)
            break;
        if(map[y][x]==1)
            break;
        else if(map[y][x]==2)
        {
            map[y][x]=1;
            snake.push({y,x});
        }
        else if(map[y][x]==0)
        {
            map[y][x]=1;
            snake.push({y,x});
            map[snake.front().first][snake.front().second]=0;
            snake.pop();
        }

        if(!change.empty())
        {
            if(change.front().first==ans)
            {
                char C=change.front().second;
                if(C=='L')
                    idx=(idx+1)%4;
                else if(C=='D')
                    idx=(idx+3)%4;
                change.pop();      
            }
        }
    }
    cout<<ans;


    return 0;
}