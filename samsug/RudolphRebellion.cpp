// 삼성 코테 2023 하반기 오후 1번 루돌프의 반란
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Santa
{
    int num;
    int y;
    int x;
    int score;
    bool isOut;
    int isStun;
};
// 상 우 하 좌 상우 하우 하좌 상좌
int dy[] = { -1,0,1,0,-1,1,1,-1 };
int dx[] = { 0,1,0,-1,1,1,-1,-1 };
/*
// 시계 반대 방향
int dry[]={-1,-1,0,1,1,1,0,-1};
int drx[]={0,-1,-1,-1,0,1,1,1};

// 상우하좌
int dsy[]={-1,0,1,0};
int dsx[]={0,1,0,-1};
*/
int N,M,P,C,D;

// 첫 턴을 1로
int curTime=1;

vector<Santa> santa;
vector< vector<int> > map;

// 루돌프
pair<int, int> rudolf;

// 산타 번호 순서대로 정렬
bool sortSanta(Santa s1, Santa s2)
{
    /*
    if(s1.num<s2.num)
        return true;
    return false
    */
    return s1.num<s2.num;
}

// 거리, 산타번호, 산타y ,산타x
bool comp(pair< pair<int, int>, pair<int, int> > p1, pair< pair<int, int>, pair<int, int> > p2) 
{
    // 거리
	if (p1.first.first == p2.first.first) 
    {
        // 거리 같으면 y좌표 먼저
		if (p1.second.first == p2.second.first) 
        {
			return p1.second.second > p2.second.second;
		}
		return p1.second.first > p2.second.first;
	}
    // 거리 다르면 짧은 것이 우선
	return p1.first.first < p2.first.first;
}

int getDist(int y1, int x1, int y2, int x2)
{
    return pow(y1-y2,2)+pow(x1-x2,2);
}

int rudolfDirection(int ry, int rx, int sy ,int sx)
{
    /*
    // 우측 상단 대각선 방향
    if(ry>sy && rx<sx)
        return 4;
    // 위로 이동
    else if(ry>sy && rx==sx)
        return 0;
    // 좌측 상단 대각선 방향 이동
    else if(ry>sy && rx>sx)
        return 7;
    // 좌측으로 이동
    else if(ry==sy && sx<rx)
        return 3;
    // 좌측 하단 대각선으로 이동
    else if(ry<sy && sx<rx)
        return 6;
    // 아래로 이동
    else if(ry<sy && sx==rx)
        return 2;
    // 우측 하단 대각선 이동
    else if(ry<sy && sx>rx)
        return 5;
    // 우측으로 이동
    else if(ry==sy && rx<sx)
        return 1;
    return 0;
    */

    if(ry>sy)
    {
        if(rx>sx) return 7;
        else if(rx==sx) return 0;
        else return 4;
    }

    else if(ry<sy)
    {
        if(rx>sx) return 6;
        else if(rx==sx) return 2;
        else return 5;
    }

    else
    {
        if(rx>sx) return 3;
        else if(rx<sx) return 1;
    }
}

int santaDirection(int y, int x)
{
    int d=-1;
    int curDist=getDist(y,x,rudolf.first,rudolf.second);
    for(int i=0;i<4;i++)
    {
        int ny=y+dy[i];
        int nx=x+dx[i];

        if(nx >= 1 && ny >= 1 && nx <= N && ny <= N && map[ny][nx]==0)
        {
            int nextDist=getDist(rudolf.first,rudolf.second,ny,nx);
            if(curDist>nextDist)
            {
                curDist=nextDist;
                d=i;
            }
        }
    }
    return d;
}

int reverseDirection(int d)
{
    return ((d+2)%4);
}

void pointIncrease()
{
    for(int i=0;i<santa.size();i++)
    {
        if(!santa[i].isOut)
            santa[i].score++;
    }
}

void colision(int nowSanta, int y, int x, int d)
{
    // 산타 이동
    if (map[y][x]==0)
    {
        santa[nowSanta].y=y;
        santa[nowSanta].x=x;
        map[y][x]=nowSanta;
    }
    // 충돌
    else
    {
        int nextSanta=map[y][x];
        int ny=y+dy[d];
        int nx=x+dx[d];

        santa[nowSanta].y=y;
        santa[nowSanta].x=x;
        map[y][x]=nowSanta;

        if(ny<1 || ny>N || nx<1 || nx>N)
        {
            santa[nextSanta].isOut=true;
            return;
        }
        
        colision(nextSanta,ny,nx,d);
    }
}

void moveRudolf()
{
    // 거리, 산타번호, 산타y좌표, 산타x좌표
    vector< pair<pair<int,int>,pair<int,int>> > v;
 
    for(int i=0;i<santa.size();i++)
    {
        if(!santa[i].isOut)
        {
            v.push_back({ {getDist(rudolf.first,rudolf.second,santa[i].y,santa[i].x),santa[i].num},{santa[i].y,santa[i].x} });
        }
    }

    sort(v.begin(),v.end(),comp);

    pair<pair<int,int>,pair<int,int>> target=v[0];

    int d=rudolfDirection(rudolf.first,rudolf.second,target.second.first,target.second.second);

    //루돌프 이동
    rudolf.first+=dy[d];
    rudolf.second+=dx[d];

    if(rudolf.first==target.second.first && rudolf.second==target.second.second)
    {
        // 충돌한 산타 점수 증가
        santa[target.first.second].score+=C;

        // 산타 튕기기
        int ny=rudolf.first+dy[d]*C;
        int nx=rudolf.second+dx[d]*C;

        // 루돌프 기존 위치 제거
        map[rudolf.first][rudolf.second]=0;

        // 맵 벗어남 -> 산타 아웃        
		if (nx > N || ny > N || nx < 1 || ny < 1) 
        {
			santa[target.first.second].isOut = true;
		}

        else 
        {
			santa[target.first.second].isStun = curTime;
			colision(target.first.second, ny, nx, d);
		}

    }
}

void moveSanta()
{
    for(int i=1;i<santa.size();i++)
    {
        // 현재 턴 - 산타가 스턴된 턴 = 1 -> 기절, 2 되면 기절 풀림
        if(santa[i].isOut || curTime-santa[i].isStun<2)
            continue;

        int y=santa[i].y;
        int x=santa[i].x;

        int d=santaDirection(y,x);
        if(d==-1)
            continue;
        // 산타 이동
        y+=dy[d];
        x+=dx[d];

        // 루돌프와 충돌
        if(y==rudolf.first && x==rudolf.second)
        {
            santa[i].score+=D;
            int nd=reverseDirection(d);

            // 산타 튕기기
            int ny=y+dy[nd]*D;
            int nx=x+dx[nd]*D;

            // 기존 산타 위치 제거
            map[santa[i].y][santa[i].x]=0;

            if (nx > N || ny > N || nx < 1 || ny < 1) 
                santa[i].isOut = true;
            else
            {
                santa[i].isStun=curTime;
                colision(i,ny,nx,nd);
            }
        }
        // 루돌프와 충돌 X
        else
        {
            map[santa[i].y][santa[i].x] = 0;
            map[y][x]=i;
            santa[i].y=y;
            santa[i].x=x;
        }
    }
}

bool isComplete()
{
    for(int i=1;i<santa.size();i++)
    {
        if(!santa[i].isOut)
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 격자크기, 턴 수, 산타 수, 루돌프힘, 산타힘
    cin>>N>>M>>P>>C>>D;
    // 루돌프 위치
    cin>>rudolf.first>>rudolf.second;

    map.resize(N+1,vector<int> (N+1,0));
    
    // 0번은 산타 X
    santa.push_back({-1,-1,-1,-1,true,-1});

    for(int i=1;i<=P;i++)
    {
        int num,y,x;
        cin>>num>>y>>x;
        santa.push_back({num,y,x,0,false,-1});
        map[y][x]=num;
    }

    sort(santa.begin(),santa.end(),sortSanta);

    for(int i=1;i<=M;i++)
    {
        moveRudolf();
        moveSanta();
        if(isComplete())
            break;
        pointIncrease();
        curTime++;
    }

    for (int i = 1; i < santa.size(); ++i)
    {
		cout << santa[i].score <<" ";
	}

}

/* 틀림

vector< vector<int> > map;
vector<bool> outSanta;
vector< pair<bool,int> > faintSanta;
vector< pair<int,int> > santas;
vector<int> santaScore;
pair<int,int> rudolp;

int rDirection;
int sDirection;

void moveRudolp()
{
    // 가장 가까운 산타에게로 1칸 이동
    // 상하좌우 대각선
    int cnt=0;
    int dist=0;
    int min=pow(N,2);

    int y=rudolp.first;
    int x=rudolp.second;

    vector<int> temp;

    for(int i=1;i<=santas.size();i++)
    {
        // 기절한 산타 X
        if(faintSanta[i].first==1)
            continue;
        // 아웃된 산타 X
        if(outSanta[i]==1)
            continue;

        // 루돌프와 산타 거리
        dist=pow(y-santas[i].first,2)+pow(x-santas[i].second,2);

        if(min>dist)
        {
            min=dist;
            cnt=0;
            temp.clear();
            temp.push_back(i);
            cnt++;
        }
        else if(min==dist)
        {
            cnt++;
            temp.push_back(i);
        }
    }

    int toSanta;
    if(cnt==1)
    {
        // 가장 가까운 산타
        toSanta=temp[0];
    }

    else if(cnt>1)
    {
        int maxR=0;
        int maxC=0;
        int candidate;

        for(int i=0;i<temp.size();i++)
        {
            if(maxR<santas[i].first)
            {
                maxR=santas[i].first;
                maxC=santas[i].second;
                candidate=i;
            }

            else if(maxR==santas[i].first)
            {
                if(santas[candidate].second<santas[i].second)
                {
                    maxC=santas[i].second;
                    candidate=i;
                }
            }
        }

        toSanta=candidate;
    }

    // toSanta로 1칸 이동
    int minLength=N*N+1;
    int direction;
    for(int i=0;i<8;i++)
    {
        int ny=rudolp.first+dry[i];
        int nx=rudolp.second+drx[i];

        if(ny<1 || ny>N || nx<1 || nx>N)
            continue;

        // 가장 가까운 거리의 산타와의 이동 후 거리
        int length=pow(ny-santas[toSanta].first,2)+pow(nx-santas[toSanta].second,2);
        if(length<minLength)
        {
            minLength=length;
            direction=i;
        }
    }

    // 루돌프 이동
    int ry=rudolp.first+dry[direction];
    int rx=rudolp.second+drx[direction];

    if(ry<1 || ry>N || rx<1 || ry>N)
        return;
    rudolp.first=ry;
    rudolp.second=rx;

    rDirection=direction;
}

void moveSanta()
{
    // 1번 산타부터 차례로 루돌프에게 거리가 가장 가까워지는 방향으로 1칸 이동
    // 다른 산타 존재, 움직일 수 없는 칸, 루돌프와 가까워질 수 없음 -> 이동 X
    // 상하좌우
    for(int i=1;i<=santas.size();i++)
    {
        if(faintSanta[i].first==1)
            continue;
        if(outSanta[i]==1)
            continue;

        int minLength=N*N+1;

        int ry=rudolp.first;
        int rx=rudolp.second;

        int direction;

        for(int j=0;j<4;j++)
        {
            int py=santas[i].first;
            int px=santas[i].second;

            int ny=py+dsy[j];
            int nx=px+dsx[j];

            if(ny<1 || ny>N || nx<1 || nx>N)
                continue;
            if(map[ny][nx]==1)
                continue;

            int length=pow(ry-ny,2)+pow(rx-nx,2);

            if(minLength>length)
            {
                minLength=length;
                direction=j;
            }

            if(minLength==N*N+1)
                continue;
            // 산타 이동
            else
            {
                // 산타 1칸 이동
                int sy=santas[i].first+dsy[direction];
                int sx=santas[i].second+dsx[direction];

                if(sy<1 || sy>N || sx<1 || sx>N)
                    continue;
                santas[i].first=sy;
                santas[i].second=sx;
                // 맵에 산타 있는 위치 표기 변경
                map[py][px]=0;
                map[santas[i].first][santas[i].second]=1;
            }
        }  
        sDirection=direction; 
    }

}

int findSanta(int y, int x)
{
    for(int i=1;i<=santas.size();i++)
    {
        if(santas[i].first==y && santas[i].second==x)
            return i;
    }

    return 0;
}

void interaction(int santa, int type)
{
    // 충돌 후 착지하게 되는 칸에서만
    // 산타 충돌 후 착지하는 지점에 산타 존재 -> 기존 산타는 1칸 이동

    // 루돌프가 산타에 충돌
    if(type==1)
        {
        int sy=santas[santa].first;
        int sx=santas[santa].second;

        // 착지 지점에 산타 있음
        int existSanta=0;
        if(map[sy][sx]==1)
        {
            for(int i=1;i<=santas.size();i++)
            {
                if((santas[i].first==sy && santas[i].second==sx) || i!=santa)
                {
                    existSanta=i;
                }
            }
        }
        // 기존 산타 1칸 이동
        santas[existSanta].first=santas[existSanta].first+dry[(rDirection+4)%8];
        santas[existSanta].second=santas[existSanta].second+drx[(rDirection+4)%8];

        int ey=santas[existSanta].first;
        int ex=santas[existSanta].second;

        if(ey<1 || ey>N || ex<1 || ex>N)
        {
            outSanta[existSanta]=1;
            return;
        }
        
        // 기존 산타 이동한 자리에 산타 존재
        if(map[ey][ex]==1)
        {
            interaction(existSanta,1);
        }
        // 기존 산타 이동한 자리에 산타 X
        else
            map[ey][ex]=1;
    }

    // 산타가 루돌프에 충돌
    else if(type==2)
    {
        int sy=santas[santa].first;
        int sx=santas[santa].second;

        // 착지 지점에 산타 있음
        int existSanta;
        if(map[sy][sx]==1)
        {
            for(int i=1;i<=santas.size();i++)
            {
                if((santas[i].first==sy && santas[i].second==sx) || i!=santa)
                {
                    existSanta=i;
                }
            }
        }
        // 기존 산타 1칸 이동
        santas[existSanta].first=santas[existSanta].first+dsy[(sDirection+2)%4];
        santas[existSanta].second=santas[existSanta].second+dsx[(sDirection+2)%4];

        int ey=santas[existSanta].first;
        int ex=santas[existSanta].second;

        if(ey<1 || ey>N || ex<1 || ex>N)
        {
            outSanta[existSanta]=1;
            return;
        }
        
        // 기존 산타 이동한 자리에 산타 존재
        if(map[ey][ex]==1)
        {
            interaction(existSanta,2);
        }
        // 기존 산타 이동한 자리에 산타 X
        else
            map[ey][ex]=1;
    }
}

void rColision()
{
    // 산타, 루돌프 같은 칸
    // 루돌프 이동 -> C만큼 점수 증가, 산타는 루돌프가 이동해온 방향으로 C만큼 이동
    int ry=rudolp.first;
    int rx=rudolp.second;

    // 산타있는 자리로 이동
    if(map[ry][rx]==1)
    {
        int santa=findSanta(ry,rx);
        // 점수 추가
        santaScore[santa]+=C;
        // 산타 기절
        faintSanta[santa].first=1;

        // 산타 충돌 후 이동
        for(int i=0;i<C;i++)
        {
            santas[santa].first=santas[santa].first+dry[(rDirection+4)%8];
            santas[santa].second=santas[santa].second+drx[(rDirection+4)%8];
        }

        map[ry][rx]=0;
        
        int sy=santas[santa].first;
        int sx=santas[santa].second;
        
        if(sy>N || sy<1 ||sx>N ||sx<1)
        {
            outSanta[santa]=1;
            return;
        }

        // 상호작용
        if(map[sy][sx]==1)
            interaction(santa,1);
        else
            map[sy][sx]=1;
    }
}

void sCollision()
{
    // 산타 이동 -> D만큼 점수 증가, 산타는 자신이 이동해온 방향 반대로 D만큼 이동
    int ry=rudolp.first;
    int rx=rudolp.second;

    if(map[ry][rx]==1)
    {
        int santa=findSanta(ry,rx);
        santaScore[santa]+=D;
        faintSanta[santa].first=1;

        // 산타 루돌프 충돌 후 반대방향으로 이동
        for(int i=0;i<D;i++)
        {
            santas[santa].first=santas[santa].first+dsy[(sDirection+2)%2];
            santas[santa].second=santas[santa].second+dsx[(sDirection+2)%2];
        }

        map[ry][rx]=0;

        int sy=santas[santa].first;
        int sx=santas[santa].second;

        if(sy<1 || sy>N || sx<1 || sx>N)
        {
            outSanta[santa]=1;
            return;
        }

        if(map[sy][sx]==1)
            interaction(santa,2);
        else
            map[sy][sx]=1;
    }
}

void faint()
{
    // 한 턴 동안 기절
    // 루돌프는 기절한 산타에게 돌진 불가
    for(int i=1;i<=santas.size();i++)
    {
        if(faintSanta[i].first==1)
            faintSanta[i].second++;
    }
}

void recovery()
{
    for(int i=1;i<=santas.size();i++)
    {
        if(faintSanta[i].first==1 && faintSanta[i].second==2)
        {
            faintSanta[i].first=0;
            faintSanta[i].second=0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 격자크기, 턴 수, 산타 수, 루돌프힘, 산타힘
    cin>>N>>M>>P>>C>>D;

    map.resize(N+1,vector<int> (N+1,0));
    outSanta.resize(M+1,0);
    faintSanta.resize(M+1,{0,0});
    santas.resize(M+1);
    santaScore.resize(M+1,0);

    // 루돌프
    int ry,rx;
    cin>>ry>>rx;
    rudolp.first=ry;
    rudolp.second=rx;

    // 산타
    for(int i=0;i<P;i++)
    {
        int santaNum,sy,sx;
        cin>>santaNum>>sy>>sx;
        santas[santaNum].first=sy;
        santas[santaNum].second=sx;
        map[sy][sx]=1;
    }

    //게임
    for(int i=0;i<M;i++)
    {
        moveRudolp();
        rColision();
        moveSanta();
        sCollision();
        faint();
        recovery();
    }

    for(int i=1;i<=santas.size();i++)
    {
        cout<<santaScore[i]<<" ";
    }
    
    return 0;
}
*/