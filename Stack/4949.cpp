// BOJ 4949번 균형잡힌 세상

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() 
{
    stack<char> st;

    string input;

    while(true)
    {
        getline(cin,input);

        if (input == ".")
        {
            break;
        }

        for (int i=0;i<input.size();i++)
        {
            if(input[i]=='(')
            {
                st.push(input[i]);
            }

            else if(input[i]==')')
            {
                if(st.size()>0 && st.top()=='(')
                {
                    st.pop();
                }

                else
                {
                    st.push(input[i]);
                }
            }

            if(input[i]=='[')
            {
                st.push(input[i]);
            }

            else if(input[i]==']')
            {
                if(st.size()>0 && st.top()=='[')
                {
                    st.pop();
                }

                else
                {
                    st.push(input[i]);
                }
            }

            if(input[i]=='.')
            {
                if(st.empty())
                {
                    cout<<"yes"<<endl;
                }
                else
                {
                    cout<<"no"<<endl;
                }
                
                while(!st.empty())
                {
                    st.pop();
                }

            }
        }
    }
   
    return 0;

}