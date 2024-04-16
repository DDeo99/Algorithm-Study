#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int tc=0;tc<commands.size();tc++)
    {
        vector<int> temp;
        for(int i=commands[tc][0]-1;i<commands[tc][1];i++)
        {
            temp.push_back(array[i]);
        }
        sort(temp.begin(),temp.end());
        
        answer.push_back(temp[commands[tc][2]-1]);
    }
    
    return answer;
}