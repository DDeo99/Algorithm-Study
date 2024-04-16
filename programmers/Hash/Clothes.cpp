#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 의상이름, 종류
int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, int> umap;
    
    for(int i=0;i<clothes.size();i++)
    {
        // 종류 만큼 ++
        umap[clothes[i][1]]++;
    }
    
    for (auto it:umap)     
    {
        answer *= (it.second + 1);
    }
    
    answer--;
    return answer;
}