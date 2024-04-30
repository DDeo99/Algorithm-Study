//BOJ 백준 6603번 로또
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> nums;

void dfs(vector<int> &lotto, int idx, int level)
{
    if(level==6)
    {
        for(int i=0;i<6;i++)
        {
            cout<<lotto[i]<<" ";
        }
        cout<<"\n";
        return;
    }

    for(int i=idx;i<nums.size();i++)
    {
        lotto.push_back(nums[i]);
        dfs(lotto,i+1,level+1);
        lotto.pop_back();
    }
} 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(1)
    {
        int num;
        cin>>num;

        if(num==0)
            break;

        nums.resize(num);

        for(int i=0;i<num;i++)
        {
            cin>>nums[i];
        }

        vector<int> lotto;
        dfs(lotto,0,0);
        cout<<"\n";
    }

    return 0;
}