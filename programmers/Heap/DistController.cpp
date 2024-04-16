#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    sort(jobs.begin(), jobs.end()); // 요청 시간으로 정렬
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    
    int time = 0;
    int idx = 0;
    
    while (idx < jobs.size() || !pq.empty()) 
    {
        if (idx < jobs.size() && time >= jobs[idx][0]) 
        {
            pq.push({jobs[idx][0], jobs[idx][1]});
            idx++;
            continue;
        }
        
        if (!pq.empty()) 
        {
            pair<int, int> currentJob = pq.top();
            pq.pop();
            time += currentJob.second;
            answer += time - currentJob.first;
        } 
        else 
        {
            time = jobs[idx][0];
        }
    }
    
    return answer / jobs.size();
}