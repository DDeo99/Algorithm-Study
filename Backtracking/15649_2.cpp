#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> nums;
vector<bool> flag;

void NM(int N, int M, int cnt)
{
    if(cnt==M)
    {
        for(int i=0;i<M;i++)
        {
            cout<<nums[i]<<" ";
        }
        cout<<"\n";
        return;
    }

    for(int i=0;i<N;i++)
    {
        if(!flag[i])
        {
            nums[cnt]=i+1;
            flag[i]=true;
            NM(N,M,cnt+1);
            flag[i]=false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N>>M;

    nums.resize(M);
    flag.resize(N,0);

    NM(N,M,0);

    return 0;
}