// BOJ 백준 1655번 가운데를 말해요
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> nums;
priority_queue<int,vector<int>,greater<int>> minPQ;
priority_queue<int,vector<int>> maxPQ;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int num;
        cin>>num;
        if(minPQ.size()==maxPQ.size())
        {
            if(maxPQ.empty())
                maxPQ.push(num);
            else
            {
                if(minPQ.top()<num)
                {
                    int temp=minPQ.top();
                    minPQ.pop();
                    minPQ.push(num);
                    maxPQ.push(temp);
                }
                else
                    maxPQ.push(num);
            }
        }

        else if(minPQ.size()+1==maxPQ.size())
        {
            if(num<maxPQ.top())
            {
                int temp = maxPQ.top();
                maxPQ.pop();
                maxPQ.push(num);
                minPQ.push(temp);
            }
            else
            {
                minPQ.push(num);
            }
        }

        cout<<maxPQ.top()<<"\n";
    
    }

    return 0;
}