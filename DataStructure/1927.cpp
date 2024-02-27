// BOJ 백준 1927번 최소 힙
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue<int, vector<int>,greater<int>> pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin>>N;

    for(int i=0;i<N;i++)
    {
        unsigned int num;
        cin>>num;

        if(num==0)
        {
            if(pq.empty())
                cout<<0<<"\n";
            else
            {
                cout<<pq.top()<<"\n";
                pq.pop();
            }
        }
        else
        {
            pq.push(num);
        }
    }

    return 0;
}