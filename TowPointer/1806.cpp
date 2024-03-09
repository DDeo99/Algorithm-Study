// BOJ 백준 1806번 부분합
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N;
long long S;
vector<int> nums;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N>>S;

    for(int i=0;i<N;i++)
    {
        int num;
        cin>>num;
        nums.push_back(num);
    }

    int l=0;
    int r=l;
    long long sum=nums[0];
    int length=0;
    int ans=100000000;

    while(l<=r)
    {
        if(sum<S)
        {
            r++;
            if(r==N)
                break;
            sum+=nums[r];
        }

        else if(sum>=S)
        {
            length=r-l+1;
            ans=min(ans,length);

            sum-=nums[l];
            l++;
        }
    }
    if(ans!=100000000)
        cout<<ans;
    else
        cout<<0;

    return 0;
}
