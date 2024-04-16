#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for(int i=0;i<scoville.size();i++)
    {
        pq.push(scoville[i]);
    }
    

    if(pq.top()>=K)
        return 0;
    
    while(pq.size()>=2)
    {
        if(pq.top()>=K)
            break;
        
        int A=pq.top();
        pq.pop();
        int B=pq.top();
        pq.pop();
        
        pq.push(A+B*2);
        answer++;
    }
    
    if(pq.top()<K)
        answer=-1;
    
    return answer;
}