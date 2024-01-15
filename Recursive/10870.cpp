// BOJ 10870번 피보나치 수 5

#include <iostream>

using namespace std;

int fibo(int n)
{
    if(n==0)
    {
        return 0;
    }

    else if(n==1)
    {
        return 1;
    }

    else
    {
        return fibo(n-1)+fibo(n-2);
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    int res=fibo(n);

    cout<<res;

}