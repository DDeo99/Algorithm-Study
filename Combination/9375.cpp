// BOJ 백준 9375번 패션왕 신혜빈
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc;
    cin>>tc;

    for(int i=0;i<tc;i++)
    {
        int n;
        cin>>n;

        unordered_map<string,int> m;

        for(int j=0;j<n;j++)
        {
            string clothes,type;
            cin>>clothes>>type;
            
            if(m.count(type)==0)
            {
                m[type]=1;
            }

            else
             m[type]++;
        }

        int ans=1;

        for(auto e:m)
        {
            int cnt=e.second;
            ans*=(cnt+1);
        }
        cout<<ans-1<<"\n";
    }
    
    return 0;
}