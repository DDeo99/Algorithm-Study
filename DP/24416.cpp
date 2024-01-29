//BOJ 백준 24416번 알고리즘 수업-피보나치 수 1
#include <iostream>
#include <vector>

using namespace std;

int n;
int cnt1=1;
int cnt2=1;

int fibo1(int n)
{
    

    if(n==1 || n==2)
    {
        return 1;
    }

    else
    {
        cnt1++;
        return fibo1(n-1) + fibo1(n-2);
    }
}

int fibo2(int n)
{
    int cache[n];
    cache[1]=1;
    cache[2]=1;

    for(int i=3;i<n;i++)
    {
        cnt2++;
        cache[i]=cache[i-1]+cache[i-2];
    }

    return cache[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n;

    fibo1(n);
    fibo2(n);

    cout<<cnt1<<" "<<cnt2;

    return 0;
}