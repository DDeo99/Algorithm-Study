// BOJ 백준 3020번 개똥벌레
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int N,H;
vector<int> stone;
vector<int> low;
vector<int> high;

int cnt=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N>>H;

    low.resize(H+1,0);
    high.resize(H+1,0);
    stone.resize(H+1,0);

    for(int i=0;i<N;i++)
    {
        int height;
        cin>>height;

        if(i%2==0)
        {
            // 돌 끝 구간
            low[height]++;
        }
        else
        {   
            // 
            high[H-height+1]++;
        }
    }

    for(int i=H-1;i>=0;i--)
    {
        //i로 날 때 부수는 돌은 i+1일 때 부수는 돌도 부숨
        low[i]+=low[i+1];
    }

    for(int i=1;i<=H;i++)
    {
        //  i로 날 때 부수는 돌은 i-1로 날 때도 부숨
        high[i]+=high[i-1];
    }

    int min = 200000;
    for(int i=1;i<=H;i++)
    {
        stone[i]=low[i]+high[i];

        if(stone[i]<min)
        {
            min=stone[i];
            cnt=1;
        }
        else if(stone[i]==min)
        {
            cnt++;
        }
    }

    cout<<min<<" "<<cnt;
}