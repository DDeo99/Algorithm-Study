// BOJ 12789번 도키도키 간식드리미

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    int N;
    cin>>N;

    queue<int> q;
    stack<int> st;

    int order=1;

    for (int i=0;i<N;i++)
    {
        int num;
        cin>>num;
        q.push(num);
    }

    while(!q.empty())
    {
        if(q.front()==order)
        {
            q.pop();
            order++;
        }

        else
        {
            if(!st.empty() && st.top()==order)
            {
                st.pop();
                order++;
            }
            else
            {
                st.push(q.front());
                q.pop();
            }
        }
    }
  
    int stsize=st.size();

    for (int i=0;i<stsize;i++)
    {
        if(st.top()==order)
        {
            st.pop();
            order++;
        }

        else
        {
            cout << "Sad" << endl;
            break;
        }
    }

    if(st.empty())
    {
        cout << "Nice" <<endl;
    }
    
    return 0;
}