// BOJ 백준 11725번 트리의 부모 찾기

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> tree;
vector<int> parent;
vector<bool> visited;
queue<int> q;

int N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N;

    tree.resize(N+1);
    parent.resize(N+1);
    visited.resize(N+1,0);

    for(int i=0;i<N-1;i++)
    {
        int from, to;
        cin>>from>>to;
        tree[from].push_back(to);
        tree[to].push_back(from);
    }

    int root=1;
    q.push(root);

    while(!q.empty())
    {
        int cur=q.front();
        visited[cur]=1;
        q.pop();
        for(int i=0;i<tree[cur].size();i++)
        {
            int next=tree[cur][i];
            if(visited[next]==0)
            {
                q.push(next);
                parent[next]=cur;
            }
        }
    }

    for(int i=2;i<=N;i++)
    {
        cout<<parent[i]<<"\n";
    }

    return 0;
}