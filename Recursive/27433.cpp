// BOJ 백준 27433번 팩토리얼2

#include <iostream>

using namespace std;

unsigned long facto(int N)
{
    if (N==1 || N==0)
    {
        return 1;
    }

    else
    {
        return N*facto(N-1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin>>N;

    unsigned long res=facto(N);

    cout<<res;

    return 0;
}