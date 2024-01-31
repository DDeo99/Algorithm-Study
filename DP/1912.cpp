// BOJ 백준 1912번 연속합

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int sum=0;
vector<int> cache;
vector<int> nums;


// vector[idx][이동횟수]
int find_max(int n)
{
    cache[n]=nums[n];
/*
    cache[n-1]=max(nums[n-1],nums[n-1]+cache[n]);
    cache[n-2]=max(nums[n-2],nums[n-2]+cache[n-1]);
    ...
    cache[1]=max(nums[1],nums[1]+cache[2]);
*/

    for(int i=n-1;i>0;i--)
    {
        cache[i]=max(nums[i],nums[i]+cache[i+1]);
    }

    

    sort(cache.begin(),cache.end());

    return cache[n];
}

int main()
{
    cin>>n;

    nums.resize(n+1,0);
    cache.resize(n+1,-1001);

    for(int i=1;i<n+1;i++)
    {
        cin>>nums[i];
    }

    cout<<find_max(n);

    return 0;
}