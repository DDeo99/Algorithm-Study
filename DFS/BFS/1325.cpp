// BOJ 백준 1325번 효율적인 해킹

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int N,M;
vector<int> computers[10001];
vector<pair<int,int>> infested;
int maxCnt=-1;

bool compare(const pair<int,int> a, const pair<int,int> b)
{
    if(a.second==b.second)
        return a.first<b.first;
    else
        return a.second>b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N>>M;
    // 컴퓨터는 1~N

    //infested.resize(N+1,0);

    for(int i=0;i<M;i++)
    {
        int c1,c2;
        cin>>c1>>c2;
        computers[c2].push_back(c1);
    }

    for(int i=1;i<=N;i++)
    {
        queue<int> q;
        vector<bool> visited(N+1,0);
        q.push(i);
        int cnt=0;

        while(!q.empty())
        {
            int cur=q.front();
            visited[cur]=1;
            q.pop();
            cnt++;

            for(int j=0;j<computers[cur].size();j++)
            {
                int next=computers[cur][j];

                if(visited[next]==1)
                    continue;

                q.push(next);
                visited[next]=1;
            }
        }

        infested.push_back({i,cnt});

        if(maxCnt<cnt)
            maxCnt=cnt;
    }

    sort(infested.begin(),infested.end(),compare);

    for(int i = 0; i < N; i++) 
    {
        if(maxCnt == infested[i].second) 
        {
            cout << infested[i].first << " ";
        }
        else
            break;
    }

    return 0;
}