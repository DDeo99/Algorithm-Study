// BOJ 백준 20922번 겹치는 건 싫어

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
int check[200001]={0};

int K,N;
vector<int> nums;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N>>K;
    nums.resize(N+1,0);

    for(int i=1;i<=N;i++)
    {
        cin>>nums[i];
    }

    int maxLength=0;
    int start=1;
    int cnt=0;

   for(int end=1;end<=N;end++)
   {
        check[nums[end]]++;
        if(check[nums[end]]>K)
        {
            while(check[nums[end]]>K)
            {
                check[nums[start]]--;
                start++;
                cnt--;
            }
        }
        cnt++;
        maxLength=max(maxLength,cnt);
   }
    cout<<maxLength;
    return 0;
}