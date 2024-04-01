// BOJ 백준 14503번 로봇 청소기
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int N,M;
vector<vector<int>> map;
int r,c;
int d;
bool stop=0;

// d -> 0북 1동 2남 3서
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

int by[]={-1,0,1,0};
int bx[]={0,1,0,-1};

int ans=0;

void clean()
{
    while(1)
    {
        if(stop==1)
            break;
        if(map[r][c]==0)
        {
            map[r][c]=2;
            ans++;
        }

        int cnt=0;
        for(int i=0;i<4;i++)
        {
            int ny=r+dy[i];
            int nx=c+dx[i];
            if(ny<0||ny>=N||nx<0||nx>=M)
                continue;
            if(map[ny][nx]==0)
            {
                cnt++;
            }
        }

        // 주변에 청소되지 않은 빈칸 없음
        if(cnt==0)
        {
            r-=by[d];
            c-=bx[d];
            if(map[r][c]==1)
            {
                stop=1;
            }
        }

        else
        {
            d=(d+3)%4;
            int ny=r+by[d];
            int nx=c+bx[d];

            if(!(ny<0||ny>=N||nx<0||nx>=M) && map[ny][nx]==0)
            {
                r=ny;
                c=nx;
            }
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N>>M;
    map.resize(N,vector<int> (M));
    
    
    //r->y c->x
    cin>>r>>c>>d;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            int s;
            cin>>s;
            map[i][j]=s;
        }
    }
    clean();
    cout<<ans;

    return 0;
}