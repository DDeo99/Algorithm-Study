//BOJ 백준 24060번 알고리즘 수업 - 병합 정렬 1

using namespace std;

#include <iostream>
#include <vector>

int cnt=0;
int res=-1;

void merge(int* A, int p, int q, int r, int K) 
{
    int i = p; 
    int j = q + 1;
    int t = 0;
    int tmp[r+1];

    while (i <= q && j <= r) 
    {
        if (A[i] <= A[j])
        {
            tmp[t++] = A[i++];
        }
        else tmp[t++] = A[j++];
    }

    while (i <= q)  
        tmp[t++] = A[i++];
    while (j <= r)  
        tmp[t++] = A[j++];

    i = p, t = 0;

    while(i<=r)
    {
        A[i++] = tmp[t++];
        cnt++;
        if(cnt==K)
        {
            res = tmp[--t];
        }
    }
}

void merge_sort(int* A, int p ,int r, int K) 
{ 
    if (p < r)
     {
        int q = (p+r)/2;

        merge_sort(A, p, q, K);   

        merge_sort(A, q + 1, r, K); 

        merge(A, p, q, r, K);       
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin>>N>>K;

    int* A;
    A = new int[N];

    int num;
    for(int i=0;i<N;i++)
    {
        cin>>num;
        A[i]=num;
    }

    merge_sort(A,0,N-1, K);

    cout<<res<<endl;

    delete[] A;

    return 0;
}