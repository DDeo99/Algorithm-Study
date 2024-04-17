#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited;
    visited.resize(n,0);
    
    for(int k=0;k<n;k++)
    {
        queue<int> q;
        if(visited[k]==0)
        {
            q.push(k);
            visited[k]=1;
            answer++;
        }
        else
            continue;
        
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();

            for(int i=0;i<n;i++)
            {
                if(i==cur)
                    continue;
                if(visited[i])
                    continue;
                if(computers[cur][i]==1)
                {
                    q.push(i);
                    visited[i]=1;
                }
            }
        }
    }
    
    return answer;
    
}