// BOJ 백준 2447번 별 찍기 - 10

#include <iostream>

using namespace std;

void star(int i, int j, int N)
{
    if((i/N)%3==1 && (j/N)%3==1)
    {
        cout<<' ';
    }
    
    else
    {
        if(N>=3)
        {
            star(i,j,N/3);
        }

        else
        {
            cout<<'*';
        }
    }
   
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin>>N;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            star(i,j,N);
        }
        cout<<endl;
    }

    return 0;
}