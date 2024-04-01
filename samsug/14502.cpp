// BOJ 백준 14502번 연구소
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N,M;
vector<vector<int>> map;
vector<vector<int>> temp;
vector<vector<bool>> visited;
vector<bool> visited2;
vector<pair<int,int>> mapArray;
//queue<pair<int,int>> q;
int ans=0;

int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};

void bfs()
{
    queue<pair<int,int>> q;

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            if(temp[i][j]==2)
            {
                q.push({i,j});
            }
        }
    }

    while(!q.empty())
    {
        pair cur=q.front();
        int cy=cur.first;
        int cx=cur.second;
        q.pop();

        for(int i=0;i<4;i++)
        {
            int ny=cy+dy[i];
            int nx=cx+dx[i];

            if(ny<1||ny>N||nx<1||nx>M)
                continue;
            if(temp[ny][nx]==0)
            {
                temp[ny][nx]=2;
                q.push({ny,nx});
            }
        }
    }
}

void dfs(int level,int idx)
{
    if(level==3)
    {
        temp=map;

        int cnt=0;
        for(int n=0;n<mapArray.size();n++)
        {
            if(cnt==3)
                break;
            if(visited2[n]==1)
            {
                int y=mapArray[n].first;
                int x=mapArray[n].second;
                temp[y][x]=1;
                cnt++;
            }
        }

        bfs();

        int res=0;
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)
            {
                if(temp[i][j]==0)
                    res++;
            }
        }
        ans=max(res,ans);
        return;
    }

    for(int i=idx;i<mapArray.size();i++)
    {
        if(visited2[i]==1)
            continue;
        visited2[i]=1;
        dfs(level+1,i);
        visited2[i]=0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N>>M;

    map.resize(N+1,vector<int> (M+1,0));
    temp.resize(N+1,vector<int> (M+1,0));
    visited.resize(N+1,vector<bool> (M+1,0));

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            cin>>map[i][j];
            if(map[i][j]==0)
            {
                mapArray.push_back({i,j});
            }
        }
    }
    visited2.resize(mapArray.size(),0);

    dfs(0,0);
    
    cout<<ans;

    return 0;
}

/*
void bfs()
{    
    queue<pair<int, int>> q;
	for(int i=1; i<=N; i++) 
    {
		for(int j=1; j<=M; j++)
         {
			if(temp[i][j]==2) 
            {
				q.push({i, j});
			}
		}
	}

    while(!q.empty())
    {
        int cy=q.front().first;
        int cx=q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++)
        {
            int ny=cy+dy[i];
            int nx=cx+dx[i];
            if(nx<1 || nx>M || ny<1 || ny>N)
                continue;
            if(temp[ny][nx]==0)
            {
                temp[ny][nx]=2;
                q.push({ny,nx});
            }
        }
    }

    int cnt=0;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            if(temp[i][j]==0)
                cnt++;
        }
    }
    ans=max(ans,cnt);
}

void dfs(int level, int idx)
{
    if(level==3)
    {
        temp=map;
        int cnt=0;
        for(int i=0;i<mapArray.size();i++)
        {
            if(cnt==3)
                break;
            if(visited2[i])
            {
                int y=mapArray[i].first;
                int x=mapArray[i].second;
                temp[y][x]=1;
                cnt++;
            }
        }
       
        bfs();
        return;
    }

    for(int i=idx;i<mapArray.size();i++)
    {
        if(visited2[i]==1)
            continue;
        visited2[i]=1;
        dfs(level+1,i);
        visited2[i]=0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N>>M;
    map.resize(N+1,vector<int>(M+1,-1));
    temp.resize(N+1,vector<int>(M+1));
    //visited.resize(N+1,vector<bool>(M+1));
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            // 1:벽 2:바이러스
            int num;
            cin>>num;
            map[i][j]=num;
            // 이렇게 풀면 틀림
            // bfs 새로 돌릴 때마다 리셋되어야 함
            //if(map[i][j]==2)
            //{
            //    q.push({i,j});
            //}

            if(map[i][j]==0)
            {
                mapArray.push_back({i,j});
            }
        }
    }

    visited2.resize(mapArray.size(),0);

    dfs(0,0);

    cout<<ans;


    return 0;
}
*/