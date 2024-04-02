// BOJ 백준 14889번 스타트와 링크
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[21]={0,};

int N;

int map[21][21]={};

int ans=100000000;

void dfs(int level,int idx)
{
    if(level==N/2)
    {
        vector<int> start;
        vector<int> link;

        for(int i=1;i<=N;i++)
        {
            if(visited[i]==1)
            {
                start.push_back(i);
            }
            else if(visited[i]==0)
            {
                link.push_back(i);
            }
        }
        
        int startS=0;
        int linkS=0;

        for(int i=0;i<N/2-1;i++)
        {
            for(int j=i+1;j<N/2;j++)
            {
                if(i!=j)
                {
                    startS+=(map[start[i]][start[j]]+map[start[j]][start[i]]);
                    linkS+=(map[link[i]][link[j]]+map[link[j]][link[i]]);
                }
            }
        }

        ans=min(ans,abs(startS-linkS));
    
        return;
    }

    for(int i=idx;i<=N;i++)
    {
        if(visited[i]==1)
            continue;
        visited[i]=1;
        dfs(level+1,i);
        visited[i]=0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin>>map[i][j];
        }
    }

    dfs(0,1);

    cout<<ans;

    return 0;
}