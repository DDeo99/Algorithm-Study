// BOJ 백준 15652번 N과 M (4)

#include <iostream>
#include <vector>

using namespace std;

void BT4(vector<int> &nums, vector<int> &flag, int N, int M, int level)
{
    if(level==M && M==1)
    {
        for(auto e:nums)
        {
            cout<<e<<" ";
        }
        cout<<'\n';
        return;
    }

    if(level==M && M>=2)
    {
        for(int i=0;i<M-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                return;
            }
        }

        for(auto e:nums)
        {
            cout<<e<<" ";
        }
        cout<<'\n';
        return;
    }

    for(int i=0;i<N;i++)
    {
        flag[i]=0;
        if(flag[i]==0)
        {
            nums[level]=i+1;
            flag[i]=1;

            BT4(nums,flag,N,M,level+1);
            flag[i]=0;
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin>>N>>M;
    int level=0;

    vector<int> nums(M,0);
    vector<int> flag(N,0);

    BT4(nums,flag,N,M,level);

    return 0;
}