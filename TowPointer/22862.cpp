// BOJ 백준 22862번 가장 긴 짝수 연속한 부분 수열(large)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nums;
int N,K;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;

    for(int i=0;i<N;i++)
    {
        int num;
        cin>>num;
        nums.push_back(num);
    }

    int left=0;
    int right=0;
    int totalLength=0;
    int oddCnt=0;
    int ans=0;

    while(right<N)
    {
        if(nums[right]%2==0)
        {
            totalLength++;
            right++;
            ans=max(ans,totalLength-oddCnt);
        }

        else if(nums[right]%2==1)
        {
            if(oddCnt<K)
            {
                oddCnt++;
                totalLength++;
                right++;
            }
            else
            {
                if(right>left)
                {
                    if(nums[left]%2==1)
                        oddCnt--;
                    left++;
                    totalLength--;
                }
                else if(left==right)
                {
                    left++;
                    right++;
                }
            }
        }
    }
    cout<<ans;

    return 0;
}
