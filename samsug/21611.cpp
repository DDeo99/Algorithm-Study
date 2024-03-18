// BOJ 백준 21611번 마법사 상어와 블리자드

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string.h>
using namespace std;

vector<vector<int>> map;

int N,M;
// 상 하 좌 우
int bx[]={0,0,0,-1,1};
int by[]={0,-1,1,0,0};

// 좌 하 우 상
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

pair<int,int> shark;

void blizard(int d, int s)
{
    int sx=shark.first;
    int sy=shark.second;

    for(int i=0;i<s;i++)
    {
        sx+=bx[d];
        sy+=by[d];

        map[sx][sy]=0;
    }
}

void move()
{
    queue<int> q;
    // 좌, 하 -> 우 상으로 이동
    // 개수는 1 1 2 2 3 3 증가
    int cnt=0;
    int x=shark.first;
    int y=shark.second;

    for(int d=0;x!=0;d++)
    {
        d%=4;
        if(d%2==0)
            cnt++;
        for(int i=0;i<cnt;i++)
        {
            x+=dx[d];
            y+=dy[d];

            if(map[x][y])
            {
                q.push(map[x][y]);
                map[x][y]=0;
            }
        }
    }

    x=shark.first;
    y=shark.second;
    cnt=0;

    for(int d=0;x!=0;d++)
    {
        d%=4;
        if(d%2==0)
            cnt++;
        for(int i=0;i<cnt;i++)
        {
            x+=dx[d];
            y+=dy[d];
            
            if(q.empty())
            {
                x=0;
                break;
            }
            else
            {
                map[x][y]=q.front();
                q.pop();
            }
        }
    }
}

int bomb()
{
    int res=0;
    //폭파 - 이동 - 폭파 - 이동 반복
    while(1)
    {
        int x=shark.first;
        int y=shark.second;
        int cnt=0;
        int before=-1;
        bool isEnd=true;
        vector<pair<int,int>> temp;
        
        for(int d=0;x!=0;d++)
        {
            d%=4;
            if(d%2==0)
                cnt++;
            for(int i=0;i<cnt;i++)
            {
                x+=dx[d];
                y+=dy[d];

                if(map[x][y]==before)
                {
                    temp.push_back({x,y});
                }

                else
                {
                    if(temp.size()<4)
                    {
                        temp.clear();
                        before=map[x][y];
                        temp.push_back({x,y});
                    }
                    else
                    {
                        isEnd=false;
                        res+=before*temp.size();
                        for(int i=0;i<temp.size();i++)
                        {
                            map[temp[i].first][temp[i].second]=0;
                        }
                        temp.clear();
                        before=map[x][y];
                        temp.push_back({x,y});
                    }
                }
            }
        }
        if(isEnd)
            return res;
        else
            move();
    }
}

void change()
{
    //A 구슬 개수, B 구슬 번호
    // 그룹은 A B로 변환
    // 구슬이 맵 넘어가면 삭제
    queue<int> q;
    int x=shark.first;
    int y=shark.second;
    int cnt=0;
    int A=0, B=-1;

    for(int d=0;x!=0;d++)
    {
        d%=4;
        if(d%2==0)
            cnt++;
        for(int i=0;i<cnt;i++)
        {
            x+=dx[d];
            y+=dy[d];

            if(map[x][y]==B)
                A++;
            else
            {
                if(A>0)
                {
                    q.push(A);
                    q.push(B);
                }
                B=map[x][y];
                A=1;
            }
        }
    }

    x=shark.first;
    y=shark.second;
    cnt=0;

    for(int d=0;x!=0;d++)
    {
        d%=4;
        if(d%2==0)
            cnt++;
        for(int i=0;i<cnt;i++)
        {
            x+=dx[d];
            y+=dy[d];

            if(x==0)
                break;

            if(q.empty())
            {
                map[x][y]=0;
            }

            else
            {
                map[x][y]=q.front();
                q.pop();
            }
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N>>M;
    map.resize(N+1,vector<int>(N+1,0));
    for(int i=1;i<N+1;i++)
    {
        for(int j=1;j<N+1;j++)
        {
            cin>>map[j][i];
        }
    }

    shark.first=(N+1)/2;
    shark.second=(N+1)/2;
    int ans=0;

    for(int i=0;i<M;i++)
    {
        int d,s;
        cin>>d>>s;

        blizard(d,s);
        move();
        ans+=bomb();
        change();
    }
    cout<< ans;

    return 0;
}