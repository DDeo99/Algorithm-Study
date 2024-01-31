//BOJ 백준 9461번 파도반 수열

#include <iostream>
#include <vector>

using namespace std;

int T;
int N;

vector<long long> cache;

long long tri(int N)
{   
    if(N==1)
    {
        return cache[1]=1;
    }

    else if(N==2)
    {
        return cache[2]=1;
    }

    else if(N==3)
    {
        return cache[3]=1;
    }

    else if(cache[N]!=0)
    {
        return cache[N];
    }
    
    else
    {
        return cache[N]=tri(N-3)+tri(N-2);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>T;

    for(int i=0;i<T;i++)
    {
        cin>>N;
        cache.resize(N+1,0);
        cout<<tri(N)<<"\n";
    }


    return 0;
}