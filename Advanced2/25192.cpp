// BOJ 백준 25192번 인사성 밝은 곰곰이

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    scanf("%d",&N);

    vector<vector<string>> chat(N);

    int floor=-1;

    for(int i=0;i<N;i++)
    {
        string chatting;
        cin>>chatting;
        if(chatting=="ENTER")
        {
            floor++;
        }
        
        else
        {
            chat[floor].push_back(chatting);
        }
    }

    int res=0;

    for(int i=0;i<=floor;i++)
    {
        sort(chat[i].begin(),chat[i].end());
        auto dupl = unique(chat[i].begin(), chat[i].end());
        chat[i].erase(dupl, chat[i].end());
        res+=chat[i].size();
    }

    printf("%d",res);

    return 0;
}