// 삼성 코테 2023 상반기 메이즈러너
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

struct Runner{
    int y;
    int x;
    bool isExit=0;
};

struct Square{
    int y;
    int x;
    int length;
};

vector<Runner> runner;
vector<vector<int>> map;
vector<Square> square;

int N,M,K;
int ey;
int ex;
int ans=0;

//상 하 좌 우
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};

int getDist(int y, int x)
{
    return abs(y-ey)+abs(x-ex);
}

bool comp(Square s1, Square s2)
{
    if(s1.length==s2.length)
    {
        if(s1.y==s2.y)
        {
            return s1.x<s2.x;
        }
        return s1.y<s2.y;
    }   
    return s1.length<s2.length;
}

int findDirection(Runner r)
{
    int d=-1;

    int ry=r.y;
    int rx=r.x;

    int curDist=getDist(ry,rx);

    for(int i=0;i<4;i++)
    {
        int ny=ry+dy[i];
        int nx=rx+dx[i];

        if(ny<1 || ny>N || nx<1 || nx>N)
            continue;
        
        int nextDist=getDist(ny,nx);

        if(curDist>nextDist)
        {
            curDist=nextDist;
            d=i;
        }
    }
    return d;
}

void moveRunner()
{
    for(int i=0;i<=M;i++)
    {
        Runner curRunner=runner[i];
        int d=findDirection(curRunner);

        if(curRunner.isExit==1)
            continue;
        
        int ny = runner[i].y+dy[d];
        int nx = runner[i].x=dx[d];
        ans++;

        if(ny==ey && nx==ex)
            runner[i].isExit=1;
        else
        {
            runner[i].y=ny;
            runner[i].x=nx;
        }
    }
}

Square makeSquare()
{
    int minLength=N+1;

    for(int i=1;i<=M;i++)
    {
        Runner cRunner=runner[i];

        int length=max(abs(cRunner.y-ey),abs(cRunner.x-ex));
        int sy=max(cRunner.y,ey)-length;
        int sx=max(cRunner.x,ex)-length;
        if(sy<1)
            sy=1;
        if(sx<1)
            sx=1;

        if(minLength>length)
        {
            minLength=length;
            square.clear();
            square.push_back({sy,sx,length});
        }
        else if(minLength==length)
        {
            square.push_back({sy,sx,length});
        }
    }

    sort(square.begin(),square.end(),comp);

    return square[0];
}

void rotateSquare()
{
    vector<vector<int>> newMap(N+1,vector<int>(N+1,0));

    Square s=makeSquare();

    int y=s.y;
    int x=s.x;
    int length=s.length;

    // 벽 1씩 감소
    for(int i=y;i<y+length;i++)
    {
        for(int j=x;j<x+length;j++)
        {
            if(map[i][j])
                map[i][j]--;
        }
    }

    for(int i=y;i<y+length;i++)
    {
        for(int j=x;j<x+length;j++)
        {   
            // 좌측 상단 좌표를 (0,0)으로 이동
            int moveY=i-y;
            int moveX=j-x;

            // 회전 이후 좌표는 (y,x) -> (x,length-y-1)
            int resultY=moveX;
            int resultX=length-moveY-1;

            // 다시 좌측 상단을 y,x로 이동
            newMap[resultY+y][resultX+x]=map[y][x];
        }
    }

    for(int i=y;i<y+length;i++)
    {
        for(int j=x;j<x+length;j++)
        {  
            map[y][x]=newMap[y][x];
        }
    }
}

void rotateTAE()
{
    Square s=makeSquare();

    int y=s.y;
    int x=s.x;
    int length=s.length;

    for(int i=1;i<=M;i++)
    {
        int ry=runner[i].y;
        int rx=runner[i].x;

        // y,x가 사각형 범위 안에 있으면 회전
        if(ry>=y && ry<y+length && rx>=x && rx<x+length)
        {
            // 좌측 상단 y,x -> 0,0 평행이동
            int moveY=ry-y;
            int moveX=rx-x;

            // 회전 후의 좌표 y,x -> x,length-y-1
            int resultY=moveX;
            int resultX=length-moveY-1;

            // 다시 원래대로 평행이동
            runner[i].y=resultY+y;
            runner[i].x=resultX+x;
        }
    }

    // 출구
    if(ey>=y && ey<y+length && ex>=x && ex<x+length)
    {
        // 좌측 상단 y,x -> 0,0 평행이동
        int moveY=ey-y;
        int moveX=ex-x;

        // 회전 후의 좌표 y,x -> x,length-y-1
        int resultY=moveX;
        int resultX=length-moveY-1;

        // 다시 원래대로 평행이동
        ey=resultY+y;
        ex=resultX+x;
    }
}

bool isComplete()
{
    for(int i=1;i<=M;i++)
    {
        if(runner[i].isExit==0)
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 미로크기 참가자수 게임시간
    cin>>N>>M>>K;
    map.resize(N+1,vector<int>(N+1));
    runner.resize(M+1);
    runner[0]={0,0,1};

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin>>map[i][j];
        }
    }

    cin>>ey>>ex;

    for(int i=1;i<=M;i++)
    {
        int y,x;
        cin>>y>>x;
        runner[i].y=y;
        runner[i].x=x;
    }

    for(int c=1;c<=K;c++)
    {
        moveRunner();
        if(isComplete)
            break;
        makeSquare();
        rotateSquare();
        rotateTAE();
    }

    cout<<ans<<"\n";
    cout<<ey<<" "<<ex;

    return 0;
}