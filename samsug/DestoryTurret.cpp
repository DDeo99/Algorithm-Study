// 삼성 코테 2023 하반기 오전 1번 포탑부수기
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <cstring>

using namespace std;

int N,M,K;
int turn=0;

vector<bool> isAtack;
struct Turret{
    int y;
    int x;
    int power;
    int atackTurn;
    bool isBroken;
    bool isActivated;
};

vector<vector<int>> map;
vector<vector<bool>> visited;
vector<vector<Turret>> turrets;
vector<Turret> route;
Turret attacker;
Turret defender;
vector<vector<pair<int,int>> > history;

//우하좌상 우하 좌하 좌상 우상
int dy[]={0,1,0,-1,1,1,-1,-1};
int dx[]={1,0,-1,0,1,-1,-1,1};

bool comp1(Turret t1, Turret t2)
{
    if(t1.power==t2.power)
    {
        if(t1.atackTurn == t2.atackTurn)
        {
            if(t1.y+t1.x==t2.y+t2.x)
            {
                return t1.x>t2.x;
            }
            return t1.y+t1.x>t2.y+t2.x;
        }
        return t1.atackTurn>t2.atackTurn;
    }

    return t1.power<t2.power;
}

bool comp2(Turret t1, Turret t2)
{
    if(t1.power==t2.power)
    {
        if(t1.atackTurn == t2.atackTurn)
        {
            if(t1.y+t1.x==t2.y+t2.x)
            {
                return t1.x<t2.x;
            }
            return t1.y+t1.x<t2.y+t2.x;
        }
        return t1.atackTurn<t2.atackTurn;
    }

    return t1.power>t2.power;
}

int count()
{
    int cnt=0;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            if(!turrets[i][j].isBroken)
                cnt++;
        }
    }
    return cnt;
}

void input()
{
    for (int i = 1; i <= N; i++) 
    {
		for (int j = 1; j <= M; j++) 
        {
			cin >> turrets[i][j].power;
			turrets[i][j].y = i;
			turrets[i][j].x = j;
			turrets[i][j].atackTurn = 0;
			turrets[i][j].isActivated = false;
			if (turrets[i][j].power == 0) 
            {
				turrets[i][j].isBroken = true;
			}
			else 
            {
				turrets[i][j].isBroken = false;
			}
		}
	}
}

void choiceAttacker()
{
    vector<Turret> temp;
    int minPower=5001;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            if(turrets[i][j].isBroken==1)
                continue;
            //if(turrets[i][j].power==0)
            //    continue;
            
            int curPower=turrets[i][j].power;
            if(minPower>curPower)
            {
                minPower=curPower;
                temp.clear();
                temp.push_back(turrets[i][j]);
            }
            else if(minPower==curPower)
                temp.push_back(turrets[i][j]);
        }
    }
    sort(temp.begin(),temp.end(),comp1);
    
    attacker=temp[0];
    attacker.power+=(N+M);
    temp.clear();
}

void choiceDefender()
{
    vector<Turret> temp;
    int maxPower=-1;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            if(turrets[i][j].isBroken==1)
                continue;
            //if(turrets[i][j].power==0)
            //    continue;
            if(turrets[i][j].y==attacker.y && turrets[i][j].x==attacker.x)
                continue;

            int curPower=turrets[i][j].power;
            if(curPower>maxPower)
            {
                temp.clear();
                maxPower=curPower;
                temp.push_back(turrets[i][j]);
            }
            else if(curPower==maxPower)
                temp.push_back(turrets[i][j]);
        }
    }
    sort(temp.begin(),temp.end(),comp2);
    defender=temp[0];
}

bool isDead(int y, int x) 
{
	if (map[y][x] == 0)
        return true;
	return false;
}

bool isIn(int y, int x) 
{
	return y >= 1 && x >= 1 && y <= N && x <= M;
}

bool isLaser()
{

    int Ay = attacker.y;
	int Ax = attacker.x;
	int Dy = defender.y;
	int Dx = defender.x;

    queue<pair<int,int> >q;
    visited[Ay][Ax]=1;
    q.push({Ay,Ax});

    bool isPossible=0;

    while(!q.empty())
    {
        int y,x;
        pair cur=q.front();
        y=cur.first;
        x=cur.second;
        q.pop();
        
        if(y==Dy && x==Dx)
        {
            isPossible=1;
            break;
        }

        for(int i=0;i<4;i++)
        {
            int ny=y+dy[i];
            int nx=x+dx[i];

            if(ny<1)
                ny+=N;
            else if(ny>N)
                ny-=N;
            if(nx<1)
                nx+=M;
            else if(nx>M)
                nx-=M;
            
            if(visited[ny][nx]==1)
                continue;
            if(map[ny][nx]==0)
                continue;

            visited[ny][nx]=1;
            history[ny][nx]={y,x};
            q.push({ny,nx});
        }
    }
    return isPossible;
}

void laserAttack()
{
    turrets[attacker.y][attacker.x].atackTurn=turn;
    turrets[attacker.y][attacker.x].isActivated=true;

    int power=attacker.power;
    int halfPower=attacker.power/2;

    for(int i=1;i<route.size();i++)
    {
        int y=route[i].y;
        int x=route[i].x;

        turrets[y][x].isActivated=true;

        if(y==defender.y && x==defender.x)
        {
            turrets[y][x].power-=power;
        }
        else
        {
            turrets[y][x].power-=halfPower;
        }

        if(turrets[y][x].power<=0)
        {
            turrets[y][x].isBroken=1;
            turrets[y][x].power=0;
        }
    }
}

void cannonAttack()
{
    turrets[attacker.y][attacker.x].atackTurn=turn;
    turrets[attacker.y][attacker.x].isActivated=true;

    int Dy=defender.y;
    int Dx=defender.x;
    int power=attacker.power;
    int halfPower=attacker.power/2;

    turrets[Dy][Dx].power-=power;
    turrets[Dy][Dx].isActivated=1;
    if(turrets[Dy][Dx].power<=0)
    {
        turrets[Dy][Dx].power=0;
        turrets[Dy][Dx].isBroken=1;
    }

    // 8방향 스플래쉬
    for(int i=0;i<8;i++)
    {
        int ny=Dy+dy[i];
        int nx=Dx+dx[i];

        if(ny>N)
            ny-=N;
        else if(ny<1)
            ny+=N;
        if(nx>M)
            nx-=M;
        else if(nx<1)
            nx+=M;   

        if(ny==attacker.y && nx==attacker.x)
            continue;
        turrets[ny][nx].power-=halfPower;
        turrets[ny][nx].isActivated=1;

        if(turrets[ny][nx].power<=0)
        {
            turrets[ny][nx].power=0;
            turrets[ny][nx].isBroken=1;
        }
    }
}

void repair()
{
    for (int i = 1; i <= N; i++) 
    {
		for (int j = 1; j <= M; j++) 
        {
			if (turrets[i][j].isBroken || turrets[i][j].isActivated)
                continue;
			turrets[i][j].power++;
		}
	}
	for (int i = 1; i <= N; i++) 
    {
		for (int j = 1; j <= M; j++) 
        {
			turrets[i][j].isActivated = false;
		}
	}
}

void Attack()
{
    choiceAttacker();
    choiceDefender();
    turrets[attacker.y][attacker.x].power=attacker.power;

    visited.resize(N+1,vector<bool> (M+1,0));
    visited[attacker.y][attacker.x]=1;
    route.clear();

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            map[i][j]=turrets[i][j].power;
        }
    }

    if(isLaser())
        laserAttack();
    else
        cannonAttack();
    
    if(count()==1)
        return;

    repair();
}

int sol()
{
    int maxPower=0;
    for (int i = 1; i <= N; i++) 
    {
		for (int j = 1; j <= M; j++) 
        {
			if (turrets[i][j].isBroken)
                continue;
			maxPower = max(maxPower, turrets[i][j].power);
		}
	}
	return maxPower;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N>>M>>K;

    map.resize(N+1,vector<int>(M+1,0));
    visited.resize(N+1,vector<bool>(M+1,0));
    turrets.resize(N+1,vector<Turret>(M+1));
    history.resize(N+1,vector<pair<int,int>>(M+1));
    input();

    for(int i=0;i<K;i++)
    {
        turn++;
        Attack();
        if(count()==1)
            break;
    }
    cout<<sol()<<"\n";

    return 0;
}