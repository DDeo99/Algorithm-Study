// BOJ 백준 11053번 가장 긴 증가하는 부분 수열
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

vector<int> nums;
// 해당 인덱스까지의 최장 거리
int cache[1001];

int N;

void findMax()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(nums[j]<nums[i])
            {
                cache[i]=max(cache[j]+1,cache[i]);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N;
    nums.resize(N+1);
    for(int i=1;i<=N;i++)
    {
        cin>>nums[i];
        cache[i]=1;
    }

    findMax();
    cout<<*max_element(cache,cache+N+1);

    return 0;
}