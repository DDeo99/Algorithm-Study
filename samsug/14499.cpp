// BOJ 백준 14499번 주사위 굴리기
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N,M,x,y,K;
vector<vector<int>> map;

// 우1 좌2 상3 하4
int dx[]={0,1,-1,0,0};
int dy[]={0,0,0,-1,1};

// 위 아래 동 서 남 북
vector<int> dice(6,0);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // x,y 입력값 반대로 받아서 하루 날림
    cin>>N>>M>>y>>x>>K;
    map.resize(N,vector<int>(M));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin>>map[i][j];
        }
    }

    for(int i=0;i<K;i++)
    {
        int command;
        cin>>command;

        y+=dy[command];
        x+=dx[command];

        if(y<0 || y>N-1 || x<0 || x>M-1)
        {
            y-=dy[command];
            x-=dx[command];
            continue;
        }
        
        vector<int> temp=dice;
        
        // 우
        // 위0 아래1 동2 서3 남4 북5
        if(command==1)
        {
            dice[0]=temp[3];
            dice[3]=temp[1];
            dice[1]=temp[2];
            dice[2]=temp[0];
        }

        // 좌
        else if(command==2)
        {
            dice[0]=temp[2];
            dice[2]=temp[1];
            dice[1]=temp[3];
            dice[3]=temp[0];
        }

        // 상
        else if(command==3)
        {
            dice[0]=temp[4];
            dice[4]=temp[1];
            dice[1]=temp[5];
            dice[5]=temp[0];
        }

        // 하
        else if(command==4)
        {
            dice[0]=temp[5];
            dice[5]=temp[1];
            dice[1]=temp[4];
            dice[4]=temp[0];
        }

        if(map[y][x]==0)
        {
            map[y][x]=dice[1];
        }
        else 
        {
            dice[1]=map[y][x];
            map[y][x]=0;
        }
        cout<<dice[0]<<"\n";
        
    }
    return 0;
}