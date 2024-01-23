// BOJ 백준 14888번 연산자 끼워넣기

#include <iostream>
#include <vector>

using namespace std;

int presentMax = -1000000001;
int presentMin = 1000000001;
int operators[4];
int N;

void findAnswer(vector<int> &nums, int result, int idx)
{
    if(idx==N)
    {
        if(result>presentMax)
        {
            presentMax=result;
        }
        if(result<presentMin)
        {
            presentMin=result;
        }
        return;
    }

    for(int i=0;i<4;i++)
    {
        if(operators[i] > 0)
        {
            operators[i]--;

            if(i==0) // +
            {
                //현재 결과값과 다음 idx의 숫자와 연산
                findAnswer(nums,result+nums[idx],idx+1);
            }

            else if(i==1) // -
            {
                findAnswer(nums,result-nums[idx],idx+1);
            }

            else if(i==2) // *
            {
                findAnswer(nums,result*nums[idx],idx+1);
            }

            else // /
            {
                findAnswer(nums,result/nums[idx],idx+1);
            }
            operators[i]++;
        }
    }
    return;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    vector<int> nums(N);

    for(int i=0;i<N;i++)
    {
        cin>>nums[i];
    }

    

    for(int i=0;i<4;i++)
    {
        cin>>operators[i];
    }

    int result=nums[0];

    findAnswer(nums,result,1);

    cout<<presentMax<<"\n";
    cout<<presentMin<<"\n";

    return 0;
}