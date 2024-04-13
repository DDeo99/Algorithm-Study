#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

// 체스판, 기사수, 명령수
int L,N,Q;

struct Knight{
    int num;
    int y;
    int x;
    int h; // 세로
    int w; // 가로
    int k; // 체력
    bool isOut=0; //탈락여부
    int damage=0;
};

vector<vector<int>> map;
vector<vector<int>> kmap;
vector<Knight> knight;
vector<int> moveList;

// 상우하좌
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

void kmapInit()
{
    kmap.resize(N+1,vector<int>(N+1,0));

    for(int i=1;i<=L;i++)
    {
        if(knight[i].k<=0)
            continue;

        int y=knight[i].y;
        int x=knight[i].x;
        int h=knight[i].h;
        int w=knight[i].w;

        for(int m=y;m<y+h;m++)
        {
            for(int n=x;n<x+w;n++)
            {
                kmap[m][n]=i;
            }
        }
    }
}

bool isPossible(int num, int d)
{   
    Knight kn=knight[num];

    if(kn.k<=0)
        return false;

    int y=kn.y;
    int x=kn.x;
    int h=kn.h;
    int w=kn.w;

    for(int i=y;i<y+h;i++)
    {
        for(int j=x;j<x+w;j++)
        {
            int ny=i+dy[d];
            int nx=j+dx[d];

            if(ny<1 || ny>N || nx<1 || nx>N)
                continue;
            if(map[ny][nx]==2)
                return false;
        }
    }
    return true;
}
void moveKnight(int num, int d)
{
    if(!isPossible(num,d))
        return;

    kmapInit();

    queue<int> q;
    q.push(num);

    while(!q.empty())
    {
        int cur=q.front();
        q.pop();

        Knight curKN=knight[cur];

        int cy=curKN.y;
        int cx=curKN.x;
        int ch=curKN.h;
        int cw=curKN.w;

        // 이동할 기사들 q에 삽입
        for(int i=cy;i<cy+ch;i++)
        {
            for(int j=cx;j<cx+cw;j++)
            {
                int ny=i+dy[d];
                int nx=j+dx[d];

                if(kmap[ny][nx]==0)
                    continue;

                // 본인 아닌 기사가 있음
                if(kmap[ny][nx]!=cur)
                {
                    if(!isPossible(kmap[ny][nx],d))
                    {
                        moveList.clear();
                        return;
                    }

                    // 만난 기사 이동 가능
                    else
                    {
                        q.push(kmap[ny][nx]);
                        if(find(moveList.begin(),moveList.end(),kmap[ny][nx])==moveList.end())
                            moveList.push_back(kmap[ny][nx]);
                    }
                }
            }
        }
        
    }
    
    for(int i=0;i<moveList.size();i++)
    {
        knight[moveList[i]].y+=dy[d];
        knight[moveList[i]].x+=dx[d];
    }
}

void updateKnight(int myNum)
{
    // 자기 제외 isAttacked=1 인 기사들 영역에 있는 장애물 만큼 hp--
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>L>>N>>Q;
    knight.resize(L+1);
    map.resize(N+1,vector<int> (N+1));
    kmap.resize(N+1,vector<int>(N+1,0));

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin>>map[i][j];
        }
    }

    knight.push_back({0,-1,-1,0,0,0,1});
    for(int i=1;i<=L;i++)
    {
        int r,c,h,w,k;
        cin>>r>>c>>h>>w>>k;
        knight[i]={i,r,c,h,w,k,0};
    }
    for(int i=1;i<=Q;i++)
    {
        int num,d;
        cin>>num>>d;
        // num번 기사 d방향으로 1칸 이동 명령
    }

    return 0;
}