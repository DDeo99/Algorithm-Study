#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N,M;
int sharkX;
int sharkY;

// 1 2 3 4 => 상하좌우
int dy[]={0,-1,1,0,0};
int dx[]={0,0,0,-1,1};

// 좌하 우상
int by[]={0,1,0,-1};
int bx[]={-1,0,1,0};

vector<vector<int>> map;

void blizard(int d, int s)
{
    int ny=sharkY;
    int nx=sharkX;
    for(int i=1;i<=s;i++)
    {
        ny+=dy[d];
        nx+=dx[d];

        map[ny][nx]=0;
    }
}

void moveBall()
{
    queue<int> q;
    int y=sharkY;
    int x=sharkX;

    int size=0;
    for(int d=0;x!=0;d++)
    {
        d%=4;
        if(d%2==0)
            size++;
        for(int i=0;i<size;i++)
        {
            y+=by[d];
            x+=bx[d];

            if(y<1 || y>N || x<1 || x>N)
            {
                x=0;
                break;
            }

            if(map[y][x]!=0)
            {
                q.push(map[y][x]);
                map[y][x]=0;
            }
        }
    }

    // q->배열
    y=sharkY;
    x=sharkX;
    size=0;

    for(int d=0;x!=0;d++)
    {
        d%=4;
        if(d%2==0)
            size++;
        for(int i=0;i<size;i++)
        {
            y+=by[d];
            x+=bx[d];

            if(x==0)
                break;

            if(y<1 || y>N || x<1 || x>N)
            {
                x=0;
                break;
            }

            if(!q.empty())
            {
                map[y][x]=q.front();
                q.pop();
            }
            else
            {
                x=0;
                break;
            }
        }
    }

}

int bomb()
{
    // q에 다시 넣고 temp에 넣으면서 뺌 -> 4개 이상이면 삭제, 아니면 다시 인풋

    int res=0;

    while(1)
    {
        bool isEnd=true;
        int before=-1;

        int y=sharkY;
        int x=sharkX;
        int size=0;

        vector<pair<int,int> > temp;

        for(int d=0;x!=0;d++)
        {
            d%=4;
            if(d%2==0)
                size++;
            for(int i=0;i<size;i++)
            {
                y+=by[d];
                x+=bx[d];

                if(y<1 || y>N || x<1 || x>N)
                {
                    x=0;
                    break;
                }

                if(before==map[y][x])
                {
                    temp.push_back({y,x});
                }
                else
                {
                    if(temp.size()<4)
                    {
                        temp.clear();
                        before=map[y][x];
                        temp.push_back({y,x});
                    }
                    else
                    {
                        isEnd=false;
                        res+=before*temp.size();
                        for(int j=0;j<temp.size();j++)
                        {
                            map[temp[j].first][temp[j].second]=0;
                        }
                        temp.clear();
                        before=map[y][x];
                        temp.push_back({y,x});
                    }
                }
            }
        }
        if(isEnd)
            return res;
        else
            moveBall();
    }
}

void changeBall()
{
   queue<int> q;

   int A=0;  // 개수
   int B=-1; // 번호

   int y=sharkY;
   int x=sharkX;
   int size=0;

   for(int d=0;x!=0;d++)
   {
        d%=4;
        if(d%2==0)
            size++;
        for(int i=0;i<size;i++)
        {
            y+=by[d];
            x+=bx[d];

            if(y<1 || y>N || x<1 || x>N)
            {
                x=0;
                break;
            }

            if(map[y][x]==B)
                A++;
            else
            {
                if(A>0)
                {
                    q.push(A);
                    q.push(B);
                }
                B=map[y][x];
                A=1;
            }
        }
   }

    y=sharkY;
    x=sharkX;
    size=0;

    for(int d=0;x!=0;d++)
    {
        d%=4;
        if(d%2==0)
            size++;
        for(int i=0;i<size;i++)
        {
            y+=by[d];
            x+=bx[d];

            if(y<1 || y>N || x<1 || x>N)
            {
                x=0;
                break;
            }

            if(!q.empty())
            {
                map[y][x]=q.front();
                q.pop();
            }
            else
            {
                x=0;
                break;
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

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin>>map[i][j];
        }
    }

    sharkY=(N+1)/2;
    sharkX=(N+1)/2;

    int ans=0;

    for(int i=1;i<=M;i++)
    {
        // 방향d, 거리s
        int d,s;
        cin>>d>>s;
        blizard(d,s);
        moveBall();
        ans+=bomb();
        changeBall();
    }
    
    cout<<ans;

    // 블리자드 -> 무브 -> 폭파 -> 무브 -> 폭파안할때까지 -> 변화
    return 0;
}