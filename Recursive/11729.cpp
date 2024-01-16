// BOJ 백준 11729번 하노이 탑 이동 순서

#include <iostream>
#include <cmath>

using namespace std;

void hanoi(int N, int from, int by, int to)
{
    if(N==1)
    {
        cout<<from<<" "<<to<<'\n';
    }

    else
    {
        hanoi(N-1,from,to,by);
        cout<<from<<" "<<to<<'\n';
        hanoi(N-1,by,from,to);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    int k=(int)pow(2,N)-1;
    // (1<<num)-1

    cout<<k<<'\n';

    hanoi(N,1,2,3);

    return 0;
}