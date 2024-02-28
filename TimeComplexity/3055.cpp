// BOJ 백준 3055번 탈출

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int R,C;
vector<vector<char>> matrix;

pair<int,int> dochi;
pair<int,int> biber;
pair<int,int> water;

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int ans=0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 도치는 비버의 굴로 이동 -> 상하좌우 1칸씩 이동 가능
    // matrix는 R행 C열
    // . : 비어있는 곳
    // * : 물 -> 상하좌우 1칸씩 이동
    // X : 돌 -> 물도 도치도 이동 불가능
    // next가 물이 찰 곳은 이동 불가능
    // 비버굴 : D
    // 도치 : S

    int R,C;
    cin>>R>>C;
    matrix.resize(R,vector<char>(C));

    queue<pair<int,int>> waterQ;
    queue<pair<int,int>> dochiQ;

    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cin>>matrix[i][j];
            if(matrix[i][j]=='D')
            {
                biber.first=i;
                biber.second=j;
            }

            else if(matrix[i][j]=='S')
            {
               dochiQ.push({i,j});
            }

            else if(matrix[i][j]=='*')
            {
                waterQ.push({i,j});
            }
        }
    }

    while(!dochiQ.empty())
    {
        int waterSize=waterQ.size();

        for(int k=0;k<waterSize;k++)
        {
            int wX=waterQ.front().first;
            int wY=waterQ.front().second;
            waterQ.pop();

            for(int i=0;i<4;i++)
            {
                int nWX=wX+dx[i];
                int nWY=wY+dy[i];

                if(nWX>=0 && nWX<R && nWY<C && nWY>=0)
                {
                    if(matrix[nWX][nWY]=='.')
                    {
                        waterQ.push({nWX,nWY});
                        matrix[nWX][nWY]='*';
                    }
                }
            }
        }

        int dochiSize=dochiQ.size();

        for(int k=0;k<dochiSize;k++)
        {
            int dX=dochiQ.front().first;
            int dY=dochiQ.front().second;
            dochiQ.pop();

            for(int i=0;i<4;i++)
            {
                int nDX=dX+dx[i];
                int nDY=dY+dy[i];
                
                if((nDX>=0 && nDX<R && nDY<C && nDY>=0))
                {
                    if(matrix[nDX][nDY]=='D')
                    {
                        ans++;
                        cout<<ans;
                        return 0;
                    }

                    if(matrix[nDX][nDY]=='.')
                    {
                        dochiQ.push({nDX,nDY});
                        matrix[nDX][nDY]='S';
                    }
                }
            }
        }
        ans++;
       
    }

    cout<<"KAKTUS";

    return 0;
}