// BOJ 백준 14888번 연산자 끼워넣기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> A;
int B[4];

int minCost=1000000001;
int maxCost=-1000000001;

void dfs(int level, int cost)
{   
    if(level==N)
    {   
        if(cost<minCost)
            minCost=cost;
        if(cost>maxCost)
            maxCost=cost;
        return;
    }
    for(int i=0;i<4;i++)
    {
        if(B[i]>0)
        {
            B[i]--;
            if(i==0)
                dfs(level+1,cost+A[level]);
            else if(i==1)
                dfs(level+1,cost-A[level]);
            else if(i==2)
                dfs(level+1,cost*A[level]);
            else if(i==3)
                dfs(level+1,cost/A[level]);
            B[i]++;
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N;

    for(int i=0;i<N;i++)
    {
        int num;
        cin>>num;
        A.push_back(num);
    }

    for(int i=0;i<4;i++)
    {
        cin>>B[i];
    }

    dfs(1,A[0]);

    cout<<maxCost<<"\n"<<minCost;
    return 0;
}