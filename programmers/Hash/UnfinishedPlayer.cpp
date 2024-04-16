#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> m;
    for(auto e:participant)
    {
        if(m.find(e)==m.end())
        {
            m.insert({e,1});
        }
        else
        {
            m[e]++;
        }
    }
    for(auto e:completion)
    {
        m[e]--;
    }
    
    for(auto e:participant)
    {
        if(m[e]>0)
        {
            answer=e;
            break;
        }
    }
    
    return answer;
}