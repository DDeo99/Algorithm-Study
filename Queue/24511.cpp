// BOJ 24511번 queuestack

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int A[1000000];
stack<int> st;
queue<int> result;

int main() 
{
    int N;
    scanf("%d",&N);

    for(int i=0;i<N;i++)
    {
        scanf("%d",&A[i]);
    }

    for(int i=0;i<N;i++)
    {
        int num;
        scanf("%d",&num);
        if(A[i] == 0)
        {
            st.push(num);
        }
    }

    while(!st.empty())
    {
        result.push(st.top());
        st.pop();
    }

    int M;
    scanf("%d",&M);

    for(int i=0;i<M;i++)
    {
        int num;
        scanf("%d",&num);
        
        if(result.empty())
        {
            result.push(num);
        }

        else
        {
           result.push(num);
        }
        printf("%d ",result.front());
        result.pop();
    }

    return 0;

}

/*
int main()
{
    int N;
    scanf("%d",&N);
    A.resize(N);
    B.resize(N);

    for(int i=0;i<N;i++)
    {
        scanf("%d",&A[i]);
    }

    for(int i=0;i<N;i++)
    {
        scanf("%d",&B[i]);
    }

    int M;
    scanf("%d",&M);
    C.resize(M);

    for(int i=0;i<M;i++)
    {
        scanf("%d",&C[i]);
    }

    for(int i=0;i<M;i++)
    {
        int pop_num=0;

        if(A[0]==0)
        {
            pop_num=B[0];
            B[0]=C[0];
        }

        else
        {
            pop_num=C[0];
        }

        for(int j=1;j<N;j++)
        {
            if(A[j]==0)
            {
                swap(B[j],pop_num);
            }
        }

        printf("%d ",pop_num);
  
    }

    return 0;
}
*/