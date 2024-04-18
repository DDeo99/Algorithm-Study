// 백준 BOJ 10799번 쇠막대기
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string str;
    cin>>str;

    stack<char> s;

    int ans=0;

    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='(')
        {
            s.push(str[i]);
        }
        else if(str[i]==')')
        {
            if(str[i-1]=='(')
            {
                // 레이저인 경우
                s.pop();
                // 레이저 기준으로 쌓여있던 레이저들 잘림
                ans+=s.size();
            }
            else
            {
                // 막대의 끝
                s.pop();
                ans++;
            }
        }
    }

    cout<<ans;

    return 0;
}