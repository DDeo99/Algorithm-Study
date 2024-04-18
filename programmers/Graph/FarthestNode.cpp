#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> nodes;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    nodes.resize(n+1);
    
    for(int i=0;i<edge.size();i++)
    {
        nodes[edge[i][0]].push_back(edge[i][1]);
        nodes[edge[i][1]].push_back(edge[i][0]);
    }
    
    vector<int> dist(n+1,-1);
    
    queue<int> q;
    q.push(1);
    dist[1]=0;
    
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        
        for(int i=0;i<nodes[cur].size();i++)
        {
            int nextNode=nodes[cur][i];
            
            if(dist[nextNode]==-1)
            {
                dist[nextNode]=dist[cur]+1;
                q.push(nextNode);
            }
        }
    }
    
    int minLenth=-1;
    for(int i=1;i<=n;i++)
    {
        if(minLenth<dist[i])
        {
            minLenth=dist[i];
            answer=1;
        }
        else if(minLenth==dist[i])
        {
            answer++;
        }
    }
    
    return answer;
}