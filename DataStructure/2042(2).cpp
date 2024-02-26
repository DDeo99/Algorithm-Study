// BOJ 백준 2042번 구간 합 구하기

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

long long N,M,K;
vector<long long> nums;
vector<long long> indexTree;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N>>M>>K;

    for(int i=0;i<N;i++)
    {
        long long num;
        cin>>num;
        nums.push_back(num);
    }

    long long k=0;
    while(pow(2,k)<N)
    {
        k++;
    }

    long long treeSize=pow(2,k)*2;

    indexTree.resize(treeSize,0);

    // 인덱스트리에 원본배열 할당
    for(int i=N-1, j=treeSize-1;i>=0;i--,j--)
    {
        indexTree[j]=nums[i];
    }

    // 인덱스트리 업데이트
    for(int i=treeSize/2-1;i>0;i--)
    {
        indexTree[i]=indexTree[i*2]+indexTree[i*2+1];
    }

   

    for(int i=0;i<M+K;i++)
    {
        int a,b;
        long long c;
        cin>>a>>b>>c;

        if(a==1)
        {
            nums[b-1]=c;
            int idx=treeSize-nums.size()+b-1;
            indexTree[idx]=c;

            while(idx>0)
            {
                if(idx%2==0)
                    indexTree[idx/2]=indexTree[idx]+indexTree[idx+1];
                else if(idx%2==1)
                    indexTree[idx/2]=indexTree[idx]+indexTree[idx-1];

                idx=idx/2;
            }
        }

        else if(a==2)
        {
            // idx = b ~ idx = c 까지의 합
            long long start = treeSize-nums.size()+b-1;
            long long end = treeSize-nums.size()+c-1;

            long long sum=0;
            while(start<=end)
            {
                if(start%2==1)
                {
                    sum+=indexTree[start];
                    start=start/2+1;
                }

                else 
                {
                    start=start/2;
                }
                
                if(end%2==0)
                {
                    sum+=indexTree[end];
                    end=end/2-1;
                }

                else
                {
                    end=end/2;
                }
            }

            cout<<sum<<"\n";
        }
    }

    return 0;
}