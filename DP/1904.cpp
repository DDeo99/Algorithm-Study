//BOJ 백준 1904번 01타일

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> cache;

int makeNum(int N)
{
    if(N==1)
    {
        return cache[1]=1;
    }

    else if(N==2)
    {
        return cache[2]=2;
    }

    else if(cache[N]!=0)
    {
        return cache[N];
    }

    else
    {
        return cache[N]=(makeNum(N-1)+makeNum(N-2))%15746;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N;

    cache.resize(N+1,0);

    cout<<makeNum(N);

    return 0;
}