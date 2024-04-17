#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;
bool visited[10001]={0};
bool flag=false;

void dfs(string cur, vector<vector<string>> tickets, int cnt)
{
    answer.push_back(cur);
    
    if(cnt==tickets.size())
    {
        flag=true;
        return;
    }
    
    for(int i=0;i<tickets.size();i++)
    {
        if(visited[i])
            continue;
        if(tickets[i][0]==cur)
        {
            visited[i]=1;
            dfs(tickets[i][1],tickets,cnt+1);
            
            // dfs가 cnt==tickets.size()에 도달하지 못한 경우 -> 마지막 것을 제외
            if(!flag)
            {
                visited[i]=0;
                answer.pop_back();
            }
        }
    }
}


vector<string> solution(vector<vector<string>> tickets) {
    
    sort(tickets.begin(),tickets.end());
    dfs("ICN",tickets,0);
    return answer;
}