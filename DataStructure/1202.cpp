// BOJ 백준 1202 가운데를 말해요
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int N,K;
vector<pair<int,int>> j;
vector<int> b;

priority_queue<int,vector<int>, less<int>> pq;

bool compare(pair<int,int> &a, pair<int,int> &b)
{
    return a>b;
}

long long ans=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N>>K;

    j.resize(N);
    b.resize(K);
    
    for(int i=0;i<N;i++)
    {
        int weight, value;
        cin>>weight>>value;
        j[i].first=weight;
        j[i].second=value;
    }
    
    sort(j.begin(),j.end());

    for(int i=0;i<K;i++)
    {
        cin>>b[i];
    }

    sort(b.begin(),b.end());

    int jIdx=0;
    for(int i=0;i<K;i++)
    {
        // 가방을 크기 순서로 정렬해놨기 때문에 j[0~jIdx]까지는 b[i+1]에 다 들어갈 수 있음
        while(jIdx<N&& b[i]>=j[jIdx].first)
        {
            pq.push(j[jIdx].second);
            jIdx++;
        }

        if(!pq.empty())
        {
            ans+=pq.top();
            pq.pop();
        }
    }

    cout<<ans;

    return 0;
}