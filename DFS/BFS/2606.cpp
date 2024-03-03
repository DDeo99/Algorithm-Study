// BOJ 백준 2606번 바이러스

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int connect;

queue<int> q;
vector<vector<int>> computers;
vector<bool> visited;
int ans=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N;
    cin>>connect;

    computers.resize(N+1);
    visited.resize(N+1,0);

    for(int i=0;i<connect;i++)
    {
        int from, to;
        cin>>from>>to;

        // 양방향 연결에 주의!!
        computers[from].push_back(to);
        computers[to].push_back(from);
    }


    q.push(1);
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        visited[cur]=1;

        for(int i=0;i<computers[cur].size();i++)
        {
            int next=computers[cur][i];
            if(visited[next]==0)
            {
                visited[next]=1;
                q.push(next);
                ans++;
            }
        }
    }

    cout<<ans;


    return 0;
}