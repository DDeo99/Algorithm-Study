// BOJ 백준 21921번 블로그
#include <iostream>
#include <vector>

using namespace std;

int N,X;
vector<int> visitor;
vector<int> sum;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N>>X;

    sum.resize(N+1,0);
    visitor.resize(N+1);

    for(int i=1;i<N+1;i++)
    {
        int num;
        cin>>num;
        visitor[i]=num;
        sum[i]=sum[i-1]+num;
    }

   int cnt=0;
   int max=0;

    for(int i=X;i<=N;i++)
    {
        int temp=sum[i]-sum[i-X];
        if(max<temp)
        {
            max=temp;
            cnt=1;
        }
        else if(max==temp)
        {
            cnt++;
        }
    }

    if(max==0)
        cout<<"SAD";
    else
    {
        cout<<max<<"\n";
        cout<<cnt;
    }
    return 0;
}