// BOJ 백준 1759번 암호 만들기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int  L,C;

vector<char> key;
vector<bool> visited;

void dfs(vector<char> ans, int level, int idx)
{
    if(level==L)
    {
        int cnt=0;
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]=='a'||ans[i]=='e'||ans[i]=='i'||ans[i]=='o'||ans[i]=='u')
                cnt++;
        }

        if(cnt<1 || ans.size()-cnt<2)
            return;

        for(int i=0;i<level;i++)
        {
            cout<<ans[i];
        }
        cout<<"\n";

        return;
    }

    for(int i=idx;i<C;i++)
    {
        ans.push_back(key[i]);
        dfs(ans,level+1,i+1);
        ans.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    cin>>L>>C;

    for(int i=0;i<C;i++)
    {
        char c;
        cin>>c;
        key.push_back(c);
    }

    sort(key.begin(),key.end());
    
    vector<char> ans;
    dfs(ans,0,0);

    return 0;
}