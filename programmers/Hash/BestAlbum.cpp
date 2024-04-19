#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool comp1(pair<int, int> a, pair<int, int> b)
{
    // 장르별 순서 정렬
    return a.first>b.first;
}

bool comp2(pair<string, int> a, pair<string, int> b)
{
    // 장르, 재생 횟수
    return a.second>b.second;
}

// i번 노래 장르, i번 노래 횟수
vector<int> solution(vector<string> genres, vector<int> plays) {
    
    vector<int> answer;
    
    // 장르, 재생횟수, 번호
    unordered_map<string, vector<pair<int,int>>> umap;
    // 장르 재생횟수
    unordered_map<string, int> playCnt;
    // 장르 재생횟수 배열
    vector<pair<string, int>> playCntV;
    
    for(int i=0;i<genres.size();i++)
    {
        // 장르 재생 횟수
        playCnt[genres[i]]+=plays[i];
        // 장르에 해당하는 재생 횟수, 노래 번호
        umap[genres[i]].push_back({plays[i],i});
    }
    
    for(auto &it:umap)
    {
        sort(it.second.begin(),it.second.end(),comp1);
    }
    
    playCntV.assign(playCnt.begin(),playCnt.end());
    // 재생 횟수에 따라 정렬
    sort(playCntV.begin(),playCntV.end(),comp2);
    
    for(int i=0;i<playCntV.size();i++)
    {
        string genre=playCntV[i].first;
        for(int j=0;j<umap[genre].size() && j<2;j++)
        {
            answer.push_back(umap[genre][j].second);
        }
    }
    
    return answer;
}