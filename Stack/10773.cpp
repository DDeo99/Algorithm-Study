// BOJ 10773번 제로

#include <iostream>
#include <stack>

using namespace std;

int main()
{

    stack<int> st;
    int K;
    cin>>K;

    for(int i=0;i<K;i++)
    {
        int num;
        cin>>num;
        num==0 ? st.pop() : st.push(num);
    }

    int sum=0;

    if(st.size()==0)
    {
        sum=0;
    }

    else
    {
        for(int i=st.size();i>1;i--)
        {
            sum+=st.top();
            st.pop();
        }
        sum+=st.top();
    }
    cout<<sum;

    return 0;
}