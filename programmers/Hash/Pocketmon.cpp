#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    int count=nums.size()/2;
    
    set<int> s;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++)
        s.insert(nums[i]);
    
    if(s.size()>count)
        answer=count;
    else
        answer=s.size();
    
    return answer;
}