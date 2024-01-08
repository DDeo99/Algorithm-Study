// BOJ 9012번 괄호

#include <iostream>
#include <stack>
#include <string>
#include <limits>

using namespace std;

int main()
{

    int T;
    cin>>T;

    cin.ignore();

    for(int i=0;i<T;i++)
    {
        string x;
        getline(cin,x);

        stack<char> st;

        for(int i=0;i<x.size();i++)
        {   
            
            if (st.size()!=0 && (st.top()=='(' && x[i]==')'))
            {
                st.pop();
            }

            else
            {
                st.push(x[i]);
            }
        }

        if(st.size()==0)
        {
           cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
        

    return 0;
}