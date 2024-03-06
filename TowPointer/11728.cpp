// BOJ 백준 11728번 배열합치기
#include <iostream>
#include <vector>

using namespace std;

vector<int> A;
vector<int> B;
vector<int> C;

int N,M;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N>>M;

    for(int i=0;i<N;i++)
    {
        int num;
        cin>>num;
        A.push_back(num);
    }

     for(int i=0;i<M;i++)
    {
        int num;
        cin>>num;
        B.push_back(num);
    }

    int i=0,j=0;
    while(C.size()<N+M)
    {
        if(i==N)
        {   
            while(j<M) 
            {
                C.push_back(B[j++]);
            }
        }

        if(j==M)
        {   
            while(i<N) 
            {
                C.push_back(A[i++]);
            }
        }

        if(A[i]<=B[j])
        {
            C.push_back(A[i]);
            i++;
        }

        else if(A[i]>B[j])
        {
            C.push_back(B[j]);
            j++;
        }
    }

    for(int i=0;i<N+M;i++)
    {
        cout<<C[i]<<" ";
    }


    return 0;
}