#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// BFS를 돌려서 도달하지 못하는 노드가 존재하면 tree X
// root는 입력에서 정해주지 않음 -> 찾아야 함
// 노드 하나만 존재해도 tree O

int findRoot(unordered_map<int,vector<int>>& edges, unordered_set<int>& indegreeNode)
{
    int cnt=0;
    int root=0;
    // indegree노드에 edges.first가 있으면 root 아님
    for(auto iter=edges.begin();iter!=edges.end();iter++)
    {
        int rootNode=iter->first;
        if(indegreeNode.count(rootNode)==0)
        {
            cnt++;
            root=rootNode;
        }

        if(cnt>=2)
        {
            return -1;
        }
    }
    return root;
}

bool BFS(unordered_map<int,vector<int>>& edges, unordered_map<int,int>& visited, int root)
{
    queue<int> q;
    q.push(root);
    visited[root]=1;
    
    while(!q.empty())
    {   
        int cur=q.front();
        q.pop();

        for(int i=0;i<edges[cur].size();i++)
        {
            int next=edges[cur][i];
            if(visited[next]==0)
            {
                q.push(next);
                visited[next]=1;
            }
            else
                return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc=0;
    bool isTree=false;
    while(1)
    {
        tc++;
        unordered_map<int,vector<int>> edges;
        unordered_set<int> indegreeNode;
        unordered_map<int,int> visited;

        while(1)
        {
            int a,b;
            cin>>a>>b;

            if(a==-1 && b==-1)
                return 0;
            if(a==0 && b==0)
                break;

            indegreeNode.insert(b);
            edges[a].push_back(b);
            if(visited.count(a)==0) visited[a]=0;
            if(visited.count(b)==0) visited[b]=0;
        }

        int root=findRoot(edges,indegreeNode);

        if(indegreeNode.size()==0)
        {
            cout<<"Case "<<tc<<" is a tree.\n";
            continue;
        }

        if(root==-1)
        {
            cout<<"Case "<<tc<<" is not a tree.\n";
            continue;
        }

        else
        {
            if(BFS(edges,visited,root))
                isTree=true;
        }

        for(auto iter=visited.begin();iter!=visited.end();iter++)
        {
            int isVisit=iter->second;
            if(isVisit==0)
            {
                isTree=false;
                break;
            }
        }

        if(isTree)
            cout<<"Case "<<tc<<" is a tree.\n";
        else
            cout<<"Case "<<tc<<" is not a tree.\n";
    }
    return 0;
}