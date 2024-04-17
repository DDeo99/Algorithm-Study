#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool comp(int a, int b)
{
    return a<b;
}

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(),citations.end(),comp);
    
    for(int i=citations[citations.size()-1];i>0;i--)
    {
        int cnt=0;
        for(int j=0;j<citations.size();j++)
        {
            if(i<=citations[j])
                cnt++;
        }
        
        if(i<=cnt)
        {
            answer=i;
            break;
        }
    }
    
    return answer;
}