// BOJ 백준 14501번 퇴사
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

// N일동안 최대한 많은 상담
// 하루에 하나씩 서로 다른 사람의 상담
// 시간 T, 금액 P
using namespace std;

int N;
vector<pair<int,int>> dnr;
// 그 날에
vector<int> cache;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N;
    dnr.resize(N+2);
    cache.resize(N+2,0);
    for(int i=1;i<=N;i++)
    {
        int T,P;
        cin>>T>>P;
        dnr[i].first=T;
        dnr[i].second=P;
    }

    int maxCost=0;
    for(int i=1;i<=N+1;i++)
    {
        cache[i]=max(maxCost,cache[i]);
        int endDay=dnr[i].first+i;
        if(endDay<=N+1)
        {
            cache[endDay]=max(cache[i]+dnr[i].second,cache[endDay]);
        }
        maxCost=max(maxCost,cache[i]);
    }

    cout<<maxCost;
    return 0;
}