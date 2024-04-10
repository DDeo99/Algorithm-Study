// 삼성 코테 2023 하반기 오전 1번 왕실의 기사 대결
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int L,N,Q;

// 상우하좌
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

vector<vector<int>> map;
vector<int> moveList;

struct Knight{
    //int num;
    int y;
    int x;
    int h;
    int w;
    int k;
    int damage=0;
    //bool isOut;
};

vector<Knight> knight;

bool isPossible(int num, int d)
{
    int y=knight[num].y;
    int x=knight[num].x;
    int h=knight[num].h;
    int w=knight[num].w;

    for(int i=y;i<y+h;i++)
    {
        for(int j=x;j<x+w;j++)
        {
            int ny=i+dy[d];
            int nx=j+dx[d];
            
            // num 번째 기사 이동 후 구간이 범위 밖
            if(ny<1 || ny>L || nx<1 || nx>L)
                return false;

            // num 번째 기사 이동 후 구간에 벽 존재
            if(map[ny][nx]==2)
                return false;
        }
    }
    return true;
}

void moveKnight(int num, int d)
{
    if(knight[num].k<=0)
        return;
    
    vector<vector<int>> knightMap(L+1,vector<int>(L+1));

    for(int cur=1;cur<=N;cur++)
    {
        int y=knight[cur].y;
        int x=knight[cur].x;
        int h=knight[cur].h;
        int w=knight[cur].w;
        int k=knight[cur].k;

        // 죽은 기사
        if(k<=0)
            continue;

        for(int i=y;i<y+h;i++)
        {
            for(int j=x;j<x+w;j++)
            {
                // 기사 맵
                knightMap[i][j]=cur;
            }
        }
    }

    queue<int> q;
    q.push(num);

    // num번 기사 못움직임
    if(isPossible(num,d)==false)
        return;

    moveList.push_back(num);
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();

        int y=knight[cur].y;
        int x=knight[cur].x;
        int h=knight[cur].h;
        int w=knight[cur].w;
        int k=knight[cur].k;

        for(int i=y;i<y+h;i++)
        {
            for(int j=x;j<x+w;j++)
            {
                int ny=i+dy[d];
                int nx=j+dx[d];

                if(nx>=1 && nx<=L && ny>=1 && ny<=L)
                {
                    // 이동 구간에 기사 없음
                    if(knightMap[ny][nx]==0)
                        continue;
                    // 이동 구간에 기사 있음 + 자기 자신은 아니어야
                    if(knightMap[ny][nx]!=cur)
                    {
                        // 이동 구간에 만난 기사 이동 가능
                        if(isPossible(knightMap[ny][nx],d))
                        {
                            q.push(knightMap[ny][nx]);
                            // 만난 기사가 moveList에 없으면
                            if(find(moveList.begin(),moveList.end(),knightMap[ny][nx])==moveList.end())
                            {
                                moveList.push_back(knightMap[ny][nx]);
                            }
                        }
                        // 이동 구간에 만난 기사 이동 불가능
                        else
                        {
                            // 전부 리셋
                            moveList.clear();
                            return;
                        }
                    }
                }
            }
        }
    }

    // 움직일 기사 전부 넣음
    // moveList 기사들 전부 이동
    for(int i=0;i<moveList.size();i++)
    {
        knight[moveList[i]].y+=dy[d];
        knight[moveList[i]].x+=dx[d];
    }
}

// 이동 후 자리에 있는 장애물 개수만큼 damage+
void updateHP(int num, int d)
{
    
    if(moveList.empty())
       return;
    for(int i=0;i<moveList.size();i++)
    {
        int cur=moveList[i];
        if(num==cur)
            continue;

        int y=knight[cur].y;
        int x=knight[cur].x;
        int h=knight[cur].h;
        int w=knight[cur].w;
        int k=knight[cur].k;
    
        int dm=0;
        for(int i=y;i<y+h;i++)
        {
            for(int j=x;j<x+w;j++)
            {
                if(map[i][j]==1)
                    dm++;
            }
        }
        if(dm>=k)
            knight[cur].k=0;
        else
        {
            knight[cur].damage+=dm;
            knight[cur].k-=dm;
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //판 크기, 기사 수, 명령 수
    cin>>L>>N>>Q;

    map.resize(L+1,vector<int>(L+1));
    knight.resize(N+1);

    for(int i=1;i<=L;i++)
    {
        for(int j=1;j<=L;j++)
        {
            // 0: 빈칸, 1: 함정, 2:벽
            cin>>map[i][j];
        }
    }

    for(int i=1;i<=N;i++)
    {
        // y x h w k damage
        cin>>knight[i].y>>knight[i].x>>knight[i].h>>knight[i].w>>knight[i].k;
    }

    for(int i=1;i<=Q;i++)
    {
        int num,d;
        cin>>num>>d;
        moveList.clear();
        moveKnight(num,d);
        updateHP(num,d);
    }

    long long ans=0;
    for(int i=1;i<=N;i++)
    {
        if(knight[i].k>0)
        {
            ans+=knight[i].damage;
        }
    }
    cout<<ans;
    return 0;
}