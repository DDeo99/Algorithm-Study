#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 5;
    vector<vector<int>> map(N+1,vector<int>(N+1));
    vector<vector<int>> newMap(N+1,vector<int>(N+1,0));

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin>>map[i][j];
        }
    }

    int y=2;
    int x=2;
    int length=2;

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
            newMap[resultY+y][resultX+x]=map[i][j];
        }
    }

    for(int i=y;i<y+length;i++)
    {
        for(int j=x;j<x+length;j++)
        {  
            map[y][x]=newMap[y][x];
        }
    }

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cout<<newMap[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}

