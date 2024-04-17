#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    sort(rocks.begin(),rocks.end());
    
    int start=0;
    int end=distance;
    
    while(start<=end)
    {
        // mid는 돌과 돌 사이 거리의 최소값
        int mid=(start+end)/2;
        int preRock=0;
        int cnt=0;
        
        for(int i=0;i<rocks.size();i++)
        {
           if(rocks[i]-preRock<mid)
               cnt++;
            else
                preRock=rocks[i];
        }
        // 마지막 바위에서 도착지점까지 거리
        if(distance-preRock<mid)
            cnt++;
        
        if(cnt>n)
            end=mid-1;
        else
        {
            answer=max(answer,mid);
            start=mid+1;
        }
    }
    
    return answer;
}