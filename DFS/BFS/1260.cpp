//BOJ 백준 1260번 DFS와 BFS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int M;
int V;
vector<bool> visited_d;
queue<int> q;
vector<bool> visited_b;
vector<vector<int>> nums;

void dfs(int cur)
{
    if(visited_d[cur])
        return;
    visited_d[cur]=1;
    cout<<cur<<" ";
    sort(nums[cur].begin(),nums[cur].end());
    for(int i=0;i<nums[cur].size();i++)
    {
        int next=nums[cur][i];
        if(visited_d[next]==0)
        {
            dfs(next);
        }
    }
}

void bfs(int num)
{
    q.push(num);
    cout<<num<<" ";
    while(!q.empty())
    {   
        int cur=q.front();
        visited_b[cur]=1;
        q.pop();
        
        sort(nums[cur].begin(),nums[cur].end());
        for(int i=0;i<nums[cur].size();i++)
        {
            int next=nums[cur][i];
            if(visited_b[next]==0)
            {
                q.push(next);
                visited_b[next]=1;
                cout<<next<<" ";
            }
        }

    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N>>M>>V;

    nums.resize(N+1);
    visited_d.resize(N+1,0);
    visited_b.resize(N+1,0);

    for(int i=0;i<M;i++)
    {
        int from, to;
        cin>>from>>to;
        nums[from].push_back(to);
        nums[to].push_back(from);
    }

    dfs(V);
    cout<<endl;
    bfs(V);

    return 0;
}