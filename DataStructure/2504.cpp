// BOJ 백준 2504번 괄호의 값
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>

using namespace std;

string st;
stack<char> myS;
int ans=0;
int temp=1;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>st;

    for(int i=0;i<st.length();i++)
    {
         //열린 괄호 -> 곱셈
        //단힌 괄호 -> 나누고 덧셈
        if(st[i]=='(')
        {
            myS.push(st[i]);
            temp*=2;
        }

        else if(st[i]=='[')
        {
            myS.push(st[i]);
            temp*=3;
        }

        else if(st[i]==')')
        {
            if(myS.empty())
            {
                ans=0;
                break;
            }

            else if(myS.top()!='(')
            {
                ans=0;
                break;
            }

            if(i>0)
            {
                if(st[i-1]=='(')
                {
                    ans+=temp;
                    temp/=2;
                }

                else
                {
                    temp/=2;
                }
            }
            myS.pop();
        
        }

        else if(st[i]==']')
        {
            if(myS.empty())
            {
                ans=0;
                break;
            }

            else if(myS.top()!='[')
            {
                ans=0;
                break;
            }

            if(i>0)
            {
                if(st[i-1]=='[')
                {
                    ans+=temp;
                    temp/=3;
                }

                else
                {
                    temp/=3;
                }
            }
            myS.pop();
        
        }
    }
    if(!myS.empty())
        cout<<0;
    else
        cout<<ans;

    return 0;
}