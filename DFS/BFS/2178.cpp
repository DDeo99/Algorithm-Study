// BOJ 백준 2178번 미로 탐색

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N,M;
vector<vector<int>> matrix;
vector<vector<bool>> visited;
vector<vector<int>> cnt;

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N>>M;

    matrix.resize(N+1,vector<int>(M+1,0));
    visited.resize(N+1,vector<bool>(M+1,0));
    cnt.resize(N+1,vector<int>(M+1,0));

    for(int i=1;i<N+1;i++)
    {
        string num;
        cin>>num;

        for(int j=0;j<num.length();j++)
        {
            matrix[i][j+1]=num[j]-'0';
        }
    }

    queue<pair<int,int>> q;

    pair start={1,1};
    q.push(start);
    cnt[1][1]=1;

    while(!q.empty())
    {
        pair cur=q.front();
        q.pop();
        int cx=cur.first;
        int cy=cur.second;
        visited[cx][cy]=1;

        for(int i=0;i<4;i++)
        {
            int nx=cx+dx[i];
            int ny=cy+dy[i];

            if(nx>=1 && nx<=N && ny>=1 && ny<=M)
            {
                if(matrix[nx][ny]==1 && visited[nx][ny]==0)
                {
                    pair next={nx,ny};
                    q.push(next);
                    visited[nx][ny]=1;
                    cnt[nx][ny]=cnt[cx][cy]+1;
                }
            }
        }
    }

    cout<< cnt[N][M];

    return 0;
}