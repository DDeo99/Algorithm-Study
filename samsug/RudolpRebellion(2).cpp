#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int N,M,P,C,D;
int ry, rx;
struct Santa{
    int num;
    int y;
    int x;
    int score;
    int sturnTime;
    bool isOut=0;

};
int turn=1;

vector<Santa> santa;
vector<vector<int>> map;
// 상 우 하 좌 상우 하우 하좌 상좌
int dy[]={-1,0,1,0,-1,1,1,-1};
int dx[]={0,1,0,-1,1,1,-1,-1};

int getDist(int y1, int x1, int y2, int x2)
{
    return pow(y1-y2,2)+pow(x1-x2,2);
}

bool sortSanta(Santa s1, Santa s2)
{
    s1.num<s2.num;
}

bool comp(Santa s1, Santa s2)
{
    if(s1.y==s2.y)
    {
        return s1.x>s2.x;
    }
    return s1.y>s2.y;
}

int nearSanta()
{
    int minDist=N*N+1;
    int santaNum=-1;

    vector<Santa> temp;

    for(int i=1;i<=P;i++)
    {
        if(santa[i].isOut)
            continue;
        int cy=santa[i].y;
        int cx=santa[i].x;
        int curDist=getDist(ry,rx,cy,cx);

        if(minDist>curDist)
        {
            minDist=curDist;
            temp.clear();
            temp.push_back(santa[i]);
        }
        else if(minDist==curDist)
        {
            temp.push_back(santa[i]);
        }
    }
    sort(temp.begin(),temp.end(),comp);

    return temp[0].num;
}

void pushSanta(int d, Santa existSanta, Santa newSanta)
{
    int esy=existSanta.y;
    int esx=existSanta.x;

    int nsy=newSanta.y;
    int nsx=newSanta.x;

    map[esy][esx]=existSanta.num;
    newSanta.y=esy;
    newSanta.x=esx;

    int ny=nsy+dy[d];
    int nx=nsx+dx[d];

    if(ny<1 || ny>N || nx<1 || ny>N)
    {
        existSanta.isOut=1;
        return;
    }

    else
    {
        if(map[ny][nx]==0)
        {
            map[ny][nx]=existSanta.num;
            existSanta.y=ny;
            existSanta.x=nx;
        }
        else
        {
            pushSanta(d,santa[map[ny][nx]],existSanta);
        }
    }
}

int moveR()
{
    int toSanta=nearSanta();

    if(toSanta==-1)
        return;

    int d=-1;

    int cy=ry;
    int cx=rx;
    int sy=santa[toSanta].y;
    int sx=santa[toSanta].x;

    int curDist=getDist(ry,rx,sy,sx);

    for(int i=0;i<8;i++)
    {
        int ny=cy+dy[i];
        int nx=cx+dx[i];

        if(ny<1 || ny>N || nx<1 || nx>N)
            continue;
        if(map[ny][nx]!=0)
            continue;
        int nextDist=getDist(ny,nx,sy,sx);

        if(curDist>nextDist)
        {
            curDist=nextDist;
            d=i;
        }
    }
    
    if(d==-1)
        return;
    
    ry+=dy[d];
    rx+=dx[d];

    // 루돌프 돌진 -> 산타 충돌
    if(ry==santa[toSanta].y && rx==santa[toSanta].x)
    {
        santa[toSanta].score+=C;
        santa[toSanta].sturnTime=turn;

        int nsy=santa[toSanta].y+dy[d]*C;
        int nsx=santa[toSanta].x+dy[d]*C;

        if(nsy<1 || nsy>N || nsx<1 || nsy>N)
        {
            santa[toSanta].isOut=1;
            map[santa[toSanta].y][santa[toSanta].x]=0;
            return;
        }

        if(map[nsy][nsx]!=0)
        {
            pushSanta(d, santa[map[nsy][nsx]], santa[toSanta]);
        }
    }
}

int santaDirection(int sy, int sx)
{
    int d=-1;
    int curDist=getDist(ry,rx,sy,sx);

    for(int i=0;i<4;i++)
    {
        int ny=sy+dy[i];
        int nx=sy+dx[i];

        if(ny<1 || ny>N || nx<1 || nx>N)
            continue;

        int nextDist=getDist(ry,rx,ny,nx);
        if(curDist>nextDist)
        {
            curDist=nextDist;
            d=i;
        }
    }
    return d;
}

void moveS()
{
    for(int i=1;i<=P;i++)
    {
        if(santa[i].isOut)
            continue;
        if(turn-santa[i].sturnTime<2)
            continue;

        int y=santa[i].y;
        int x=santa[i].x;

        int d=santaDirection(y,x);

        // 산타 이동
        int ny=y+dy[d];
        int nx=x+dx[d];

        if(map[ny][nx]!=0)
            continue;
        
        else
        {
            // 산타 이동 -> 루돌프와 충돌
            if(ny==ry && nx==rx)
            {
                santa[i].score+=D;
                santa[i].sturnTime=turn;

                int nd=(d+2)%4;

                int nsy=ny+dy[nd]*D;
                int nsx=nx+dx[nd]*D;

                if(nsy<1 || nsy>N || nsx<1 || nsy>N)
                {
                    santa[i].isOut=1;
                    map[y][x]=0;
                }
                
                else
                {
                    if(map[nsy][nsx]==0)
                    {
                        map[y][x]=0;
                        santa[i].y=nsy;
                        santa[i].x=nsx;
                        map[nsy][nsx]=i;
                    }
                    else
                    {
                        pushSanta(nd,santa[map[nsy][nsx]],santa[i]);
                    }
                }
            }

            else
            {
                map[y][x]=0;
                map[ny][nx]=santa[i].num;
                santa[i].y=ny;
                santa[i].x=nx;
            }
        }
    }
}

void pointIncreasw()
{

}

bool isComplete()
{
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 게임판크기, 턴수, 산타수, 루돌프힘, 산타힘
    cin>>N>>M>>P>>C>>D;
    cin>>ry>>rx;

    map.resize(N+1,vector<int> (M+1));
    santa.resize(P+1);


    santa[0]={0,-1,-1,-1,1};
    for(int i=1;i<=P;i++)
    {
        int num,y,x;
        cin>>num>>y>>x;
        santa[i]={num,y,x,0,-1,0};
        map[y][x]=num;
    }

    // 산타 번호 순으로 정렬
    sort(santa.begin(),santa.end(),sortSanta);
    return 0;
}