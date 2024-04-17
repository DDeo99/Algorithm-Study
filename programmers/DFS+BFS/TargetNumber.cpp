#include <string>
#include <vector>

using namespace std;

int res=0;

void dfs(vector<int> &numbers, int target, int level, int cnt, int num)
{
    if(cnt==level)
    {
        if(num==target)
        {
            res++;
        }
        return;
    }
    
    dfs(numbers,target,level,cnt+1,num+numbers[cnt]);
    dfs(numbers,target,level,cnt+1,num-numbers[cnt]);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    int level=numbers.size();
    
    dfs(numbers,target,level,0,0);
    
    return res;
}