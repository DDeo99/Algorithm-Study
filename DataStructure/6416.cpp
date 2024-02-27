// BOJ 백준 6416번 트리인가

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

int tc=0;

int findRoot(unordered_set<int>& nodes, unordered_map<int,vector<int>> &edges)
{
    int root=0, cnt=0;
    for(auto e=edges.begin();e!=edges.end();e++)
    {
        int node=e->first;

        if(nodes.count(node)==0)
        {
            cnt++;
            root=node;
        }

        if(cnt>=2)
            return -1;
    }

    return root;
}

// 방문 노드 재방문 체크
bool BFS(unordered_map<int,vector<int>> &edges,unordered_map<int,int> &visited,int root)
{
    queue<int> myQ;
    myQ.push(root);
    visited[root]=1;

    while(!myQ.empty())
    {
        int cur=myQ.front();
        myQ.pop();

        for(int i=0;i<edges[cur].size();i++)
        {
            int next=edges[cur][i];
            if(visited[next]!=1)
            {
                visited[next]=1;
                myQ.push(next);
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

    while(true)
    {   
        tc++;
        bool isTree=false;

        // 노드가 숫자 크기 순서로 입력되는 것이 아니라 map 사용함
        unordered_map<int,vector<int>> edges;
        unordered_map<int,int> visited;
        unordered_set<int> nodes;

        // 초기화
        while(1)
        {
            int a,b;
            cin>>a>>b;

            if(a==-1 && b==-1)
                return 0;
            if(a==0 && b==0)
                break;

            nodes.insert(b);
            edges[a].push_back(b);
            //visit 배열 초기화
            if(visited.count(a)==0) visited[a]=0;
            if(visited.count(b)==0) visited[b]=0;
        }

        int root=findRoot(nodes,edges);

        if(root==-1)
        {
            cout << "Case " << tc <<" is not a tree." << '\n';
            continue;
        }

        else
        {
            if(BFS(edges,visited,root))
                isTree=true;
        }

        for(auto iter=visited.begin();iter!=visited.end();iter++)
        {
            if(iter->second==0)
            {
                isTree=false;
                break;
            }
        }

        if(isTree)
            cout << "Case " << tc <<" is a tree." << '\n';
        else
            cout << "Case " << tc <<" is not a tree." << '\n';
    }

}

/*
vector<pair<int,int>> e;
set<int> node;

int tc=1;
int a,b;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(true)
    {
     
        cin>>a>>b;

        if(a==-1 && b==-1)
            break;
        if(a==0 && b==0)
        {
            if(e.size()+1==node.size() || node.size()==0)
                cout << "Case " << tc << " is a tree.\n";
            else
                cout << "Case " << tc << " is not a tree.\n";
            
            tc++;
            node.clear();
            e.clear();
        }

        else
        {
            node.insert(a);
            node.insert(b);
            e.push_back({a,b});
        }
    }
    return 0;
}
*/