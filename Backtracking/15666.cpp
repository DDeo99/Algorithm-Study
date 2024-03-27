//BOJ 백준 15666번 N과M(12)
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

void dfs(int idx, int level)
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

    for(int i=idx;i<N;i++)
    {
        if(level>0)
        {
            if(res[level-1]<=nums[i])
                res[level]=nums[i];
        }
        else
            res[level]=nums[i];
        dfs(i,level+1);
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); 

    cin>>N>>M;
    nums.resize(N);
    res.resize(M);
    visited.resize(N,0);
    for(int i=0;i<N;i++)
    {
        cin>>nums[i];
    }
    sort(nums.begin(),nums.end());

    dfs(0,0);

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