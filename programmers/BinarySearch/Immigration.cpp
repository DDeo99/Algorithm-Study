#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(),times.end());
    
    // 최소로 걸리는 시간
    long long left=1;
    // 최대로 걸리는 시간
    long long right=n*(long long)times[times.size()-1];
    
    // n명 처리하는 가장 빠른 시간을 찾는다.
    while(left<=right)
    {
        long long mid=(left+right)/2;
        
        long long completed=0;
        
        for(int i=0;i<times.size();i++)
        {
            // + i번째 심사위원이 mid 시간 동안 처리할 수 있는 사람 수 
            completed+=mid/(long long)times[i];
        }
        
        if(n<=completed)
        {
            right=mid-1;
            answer=mid;
        }
        else if(n>completed)
            left=mid+1;
    }
    
    return answer;
}