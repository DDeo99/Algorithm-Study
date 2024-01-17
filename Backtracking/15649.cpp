// BOJ 백준 15649번 N과 M (1)

#include <iostream>
#include <vector>

using namespace std;

void BT(vector<int> &nums,vector<int> &flag, int N, int M, int level)
{

    if(level==M) 
    {
        for(int i=0;i<M;i++)
        {
            cout<<nums[i]<<" ";
        }
        cout<<'\n';
        return;
    }

    for(int i=0;i<N;i++)
    {
        if(flag[i]==0)
        {
            nums[level]=i+1;
            flag[i]=1;

            BT(nums,flag,N,M,level+1);
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
    cin>> N >> M;
    int level=0;

    vector<int> nums(M);
    vector<int> flag(N,0);

    BT(nums,flag,N,M,level);

    return 0;
}