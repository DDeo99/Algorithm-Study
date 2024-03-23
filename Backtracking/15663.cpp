// BOJ 백준 15664번 N과M(10)
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int N,M;
vector<int> nums;
vector<int> res;
vector<bool> visited;
set<vector<int>> s;

void dfs(int level)
{
    if(level==M)
    {
        vector<int> v;
        for(int i=0;i<level;i++)
            v.push_back(res[i]);
        s.insert(v);
        res.clear();
        return;
    }

    for(int i=0;i<N;i++)
    {
        if(visited[i]==0)
        {   
            visited[i]=1; 
            res[level]=nums[i];
            dfs(level+1);
            visited[i]=0;
        }
    }

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N>>M;
    nums.resize(N);
    res.resize(M,0);
    visited.resize(N,0);
    for(int i=0;i<N;i++)
    {
        cin>>nums[i];
    }
    sort(nums.begin(),nums.end());
    dfs(0);

    for(auto e:s)
    {
        for(auto temp:e)
        {
            cout<<temp<<" ";
        }
        cout<<"\n";
    }

    return 0;
}