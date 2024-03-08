// BOJ 백준 2470번 두 용액

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N;
vector<long long> liquid;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N;

    for(int i=0;i<N;i++)
    {
        long long l;
        cin>>l;
        liquid.push_back(l);
    }

    sort(liquid.begin(),liquid.end());

    int left=0;
    int right=N-1;

    long long ans1,ans2;
    long long mid=INT_MAX;
    long long sum=0;

    while(left<right)
    {
        sum=liquid[left]+liquid[right];

        if(abs(sum)<mid)
        {
            ans1=liquid[left];
            ans2=liquid[right];
            mid=abs(sum);

            if(sum==0)
                break;
        }

        if(sum>0)
        {
            right--;
        }
        else
        {
            left++;
        }
    }

    cout<<ans1<<" "<<ans2;

    return 0;
}