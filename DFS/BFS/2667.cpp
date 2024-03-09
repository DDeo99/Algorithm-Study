//BOJ 백준 2667번 단지번호붙이기
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int N;
vector<vector<int>> houses;
vector<vector<bool>> visited;
vector<int> houseNum;

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N;
    houses.resize(N+1,vector<int> (N+1));
    visited.resize(N+1,vector<bool> (N+1,0));
    houseNum.resize(N*N+1);

    queue<pair<int,int>> q;
    int cnt=0;

    for(int i=0;i<N;i++)
    {
        string house;
        cin>>house;

        for(int j=0;j<house.length();j++)
        {
            houses[i][j]=house[j]-'0';
        }        
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(houses[i][j]==0 || visited[i][j]==1)
            {
                continue;
            }
            
            else if(houses[i][j]==1 && visited[i][j]==0)
            {
                pair start={i,j};
                q.push(start);
                visited[i][j]=1;
                cnt++;
                houseNum[cnt]++;
                
                while(!q.empty())
                {
                    pair cur=q.front();
                    q.pop();
                    int cx=cur.first;
                    int cy=cur.second;

                    for(int k=0;k<4;k++)
                    {
                        int nx=cx+dx[k];
                        int ny=cy+dy[k];

                        if(nx>=0 && ny<N && ny>=0 && ny<N)
                        {
                            if(visited[nx][ny]==0 && houses[nx][ny]==1)
                            {
                                q.push({nx,ny});
                                visited[nx][ny]=1;
                                houseNum[cnt]++;
                            }
                        }
                    }
                }
            }
        }
    }

    sort(houseNum.begin(),houseNum.end());

    cout<<cnt<<"\n";
    for(int i=houseNum.size()-cnt;i<=houseNum.size()-1;i++)
    {
        cout<<houseNum[i]<<"\n";
    }


    return 0;
}