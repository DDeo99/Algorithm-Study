// BOJ 백준 2108번 통계학

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

int main() 
{

    int N;
    scanf("%d",&N);

    int avg,mid,most,dif;
    vector<int> nums;
    map<int, int> frequency;

    for(int i=0;i<N;i++)
    {
        int num;
        scanf("%d",&num);
        nums.push_back(num);
    }

    if(N==1)
    {
        avg=nums[0];
        mid=nums[0];
        most=nums[0];
        dif=0;
    }

    else
    {
        for(int num : nums)
        {
            frequency[num]++;
        }

        vector<pair<int,int>> frequencyVector(frequency.begin(), frequency.end());

        sort(frequencyVector.begin(),frequencyVector.end(),[](const auto &left, const auto &right)
        {
            return left.second > right.second;
        });

        sort(nums.begin(),nums.end());

        int sum=0;

        for(int i=0;i<N;i++)
        {
            sum+=nums[i];
        }

        double double_avg = static_cast<double>(sum)/N;

        avg =round(double_avg);

        mid=nums[(N-1)/2];

        if (frequencyVector.size() > 1 && frequencyVector[0].second == frequencyVector[1].second) 
        {
             most = frequencyVector[1].first;
        }

        else
        {
            most = frequencyVector[0].first;
        }

        dif=nums[N-1]-nums[0];
    }

    printf("%d\n",avg);
    printf("%d\n",mid);
    printf("%d\n",most);
    printf("%d\n",dif);

    return 0;

}
