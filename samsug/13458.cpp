// BOJ 백준 13458번 시험 감독
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int N,B,C;
vector<int> A;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 시험장 개수
    cin>>N;
    // 각 시험장의 사람수
    A.resize(N);
    for(int i=0;i<N;i++)
    {
        cin>>A[i];
    }
    // 총감독관 커버 가능 인원, 부감독관 수 커버 가능 인원
    cin>>B>>C;

    sort(A.begin(),A.end());

    long long cnt=0;

    for(int i=0;i<N;i++)
    {
        A[i]-=B;
        cnt++;
    }

    for(int i=0;i<N;i++)
    {
        if(A[i]<=0)
            continue;
        if(A[i]%C==0)
            cnt+=A[i]/C;
        else if(A[i]%C!=0)
            cnt+=(A[i]/C+1);
    }
    cout<<cnt;
    return 0;
}