#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 칸수, 게임횟수, 산타수, 루돌프힘, 산타힘
int N,M,P,C,D;
pair<int,int> rudolf;
struct Santa{
    int num;
    int y;
    int x;
    int score;
    int sturnTime;
    bool isFail;
};
int turn=1;
vector<vector<int>> map;
vector<Santa> santas;

// 상 우 하 좌 상우 하우 하좌 상좌
int dy[]={-1,0,1,0,-1,1,1,-1};
int dx[]={0,1,0,-1,1,1,-1,-1};

// 거리 구하기
int getDist(int y1, int x1, int y2, int x2)
{
    return pow(y1-y2,2)+pow(x1-x2,2);
}

bool sortSanta(Santa s1, Santa s2)
{
    // 작은 번호가 먼저
    return s1.num<s2.num;
}

// 거리, 산타번호, 산타y, 산타x
bool comp(pair< pair<int,int>, pair<int,int> > p1, pair< pair<int,int>, pair<int,int> > p2)
{
    // 산타 정렬 기준
    if(p1.first.first==p2.first.first)
    {
        // 거리 같으면 y 큰 것 우선, y도 같으면 x 큰 것 우선
        if(p1.second.first==p2.second.first)
        {
            return p1.second.second>p2.second.second;
        }
        else
            return p1.second.first>p2.second.first;
    }
    else
        return p1.first.first<p2.first.first;
}

int nearSanta()
{
    int ry=rudolf.first;
    int rx=rudolf.second;

    // 거리, 산타번호, 산타y, 산타x
    vector<pair< pair<int,int>, pair<int,int> >> temp;

    for(int i=1;i<santas.size();i++)
    {
        if(santas[i].isFail)
            continue;
        temp.push_back({{getDist(ry,rx,santas[i].y,santas[i].x),santas[i].num},{santas[i].y,santas[i].x}});
    }
    sort(temp.begin(),temp.end(),comp);
    
    pair<pair<int,int>, pair<int,int>> target=temp[0];

    int santaNum=target.first.second;

    return santaNum;
}

int rudolfDirection(int sy,int sx)
{
    int ry=rudolf.first;
    int rx=rudolf.second;

    if(ry>sy)
    {
        if(rx==sx) return 0;
        else if(rx>sx) return 7;
        else return 4;
    }
    else if(ry==sy)
    {
        if(rx>sx) return 3;
        else return 1;
    }
    else
    {
        if(rx>sx) return 6;
        else if(rx==sx) return 2;
        else return 5;
    }
}

int santaDirection(int sy, int sx)
{
    // 이동할 방향찾기
    int direction=-1;

    int cDist=getDist(rudolf.first,rudolf.second,sy,sx);
    
    for(int i=0;i<4;i++)
    {
        int ny=sy+dy[i];
        int nx=sx+dx[i];

        // 아무것도 없으면서 범위 내
        if(ny>=1 && ny<=N && nx>=1 && nx<=N && map[ny][nx]==0)
        {
            int nDist=getDist(rudolf.first,rudolf.second,ny,nx);
            if(cDist>nDist)
            {
                cDist=nDist;
                direction=i;
            }
        }
    }
    return direction;
}

int reverseDirection(int d)
{
    return (d+2)%4;
}

void chainMove(int ny, int nx, int direction, int firstSanta)
{
   // 산타 튕김
   // 튕긴 자리 비어있음
   if(map[ny][nx]==0)
   {
        map[ny][nx]=firstSanta;
        santas[firstSanta].y=ny;
        santas[firstSanta].x=nx;
        return;
   }
   // 튕긴 자리에 다른 산타 존재
   else
   {
        int secondSanta=map[ny][nx];
        
        map[ny][nx]=firstSanta;
        santas[firstSanta].y=ny;
        santas[firstSanta].x=nx;

        ny+=dy[direction];
        nx+=dx[direction];

        if(ny<1 || ny>N || nx<1 || ny>N)
        {
            santas[secondSanta].isFail=1;
            return;
        }
        else
            chainMove(ny,nx,direction,secondSanta);
   }
}

// 루돌프 움직임
void moveRudolf()
{
    int toSanta=nearSanta();
    int direction=rudolfDirection(santas[toSanta].y,santas[toSanta].x);
    /*
     // 거리, 산타번호, 산타y좌표, 산타x좌표
    vector< pair<pair<int,int>,pair<int,int>> > v;
 
    for(int i=0;i<santas.size();i++)
    {
        if(!santas[i].isFail)
        {
            v.push_back({ {getDist(rudolf.first,rudolf.second,santas[i].y,santas[i].x),santas[i].num},{santas[i].y,santas[i].x} });
        }
    }

    sort(v.begin(),v.end(),comp);

    pair<pair<int,int>,pair<int,int>> target=v[0];

    int direction=rudolfDirection(target.second.first,target.second.second);
    int toSanta=target.first.second;
    */
    // 루돌프 1칸 이동
    rudolf.first+=dy[direction];
    rudolf.second+=dx[direction];
    
    // 루돌프 산타 충돌
    if(rudolf.first==santas[toSanta].y && rudolf.second==santas[toSanta].x)
    {
        santas[toSanta].score+=C;
        santas[toSanta].sturnTime=turn;
        
        int y=santas[toSanta].y;
        int x=santas[toSanta].x;

        map[y][x]=0;

        y+=dy[direction]*C;
        x+=dx[direction]*C;

        // 아웃
        if(y<1 || y>N || x<1 || x>N)
        {
            santas[toSanta].isFail=1;
        }

        // 아웃 안남
        else
        {
            // 산타 튕김
            chainMove(y,x,direction,toSanta);
        }
    }
}

// 산타 움직임
void moveSanta()
{
    for(int i=1;i<=P;i++)
    {
        if(santas[i].isFail || turn-santas[i].sturnTime<2)
            continue;

        int direction=santaDirection(santas[i].y,santas[i].x);
        if(direction==-1)
            continue;
        
        int y=santas[i].y;
        int x=santas[i].x;

        map[y][x]=0;

        y+=dy[direction];
        x+=dx[direction];

        // 산타와 충돌
        if(rudolf.first==y && rudolf.second==x)
        {
            santas[i].sturnTime=turn;
            santas[i].score+=D;

            int nd=reverseDirection(direction);

            y+=dy[nd]*D;
            x+=dx[nd]*D;

            if(y<1 || y>N || x<1 || x>N)
            {
                santas[i].isFail=1;
            }

            else
            {
                chainMove(y,x,nd,santas[i].num);
            }
        
        }
        // 충돌 안함
        else
        {
            map[y][x]=santas[i].num;
            santas[i].y=y;
            santas[i].x=x;
        }
    }
}

void pointIncrease()
{
    for(int i=1;i<santas.size();i++)
    {
        if(!santas[i].isFail)
            santas[i].score++;
    }
}

bool isComplete()
{
  
    for(int i=1;i<santas.size();i++)
    {
        if(!santas[i].isFail)
            return false;
    }
    return true;
}

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N>>M>>P>>C>>D;
    cin>>rudolf.first>>rudolf.second; // (y,x)

    // 게임판 구성
    map.resize(N+1,vector<int>(N+1,0));
    // 산타는 1번부터
    // num,y,x,score,sturn걸린 턴, 탈락여부
    santas.push_back({-1,-1,-1,-1,-1,1}); // -> 범위 아웃 값 넣어야 함...

    for(int i=1;i<=P;i++)
    {
        int num,y,x;
        cin>>num>>y>>x;
        map[y][x]=num;
        santas.push_back({num,y,x,0,-1,false}); // turn -1보다 이하로 넣어야 turn-sturnTime<2 조건 처음에 안걸림
    }

    // 번호순 정렬
    sort(santas.begin(),santas.end(),sortSanta);

    for(int i=1;i<=M;i++)
    {
        moveRudolf();
        moveSanta();
        if(isComplete())
            break;
        pointIncrease();
        turn++;
    }
    for(int i=1;i<=P;i++)
    {
        cout<<santas[i].score<<" ";
    }

    return 0;
}