//BOJ 9184번 신나는 함수 실행

#include <iostream>
#include <vector>

using namespace std;

int a,b,c;
int cache[21][21][21];

int printW(int a, int b, int c)
{
    if(a<=0 || b<=0 || c<=0)
    {
        a=0; b=0; c=0;
    }
    
    if(a>20||b>20||c>20)
    {
        a=20; b=20; c=20;
    }
      
    if(cache[a][b][c]!=-1)
    {
        return cache[a][b][c];
    }

    if(a<b && b<c)
    {
        return cache[a][b][c]=printW(a,b,c-1) + printW(a,b-1,c-1)-printW(a,b-1,c);
    }

    else
    {
        return cache[a][b][c]=printW(a-1,b,c) + printW(a-1,b-1,c) + printW(a-1,b,c-1) - printW(a-1,b-1,c-1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
  
    for(int i=0;i<21;i++)
    {
        for(int j=0;j<21;j++)
        {
            for(int k=0;k<21;k++)
            {
                cache[i][j][k]=-1;
            }
        }
    }
    cache[0][0][0]=1;

    while(1)
    {
        cin>>a>>b>>c;
        if(a==-1 && b==-1 && c==-1)
        {
            break;
        }
        
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<printW(a,b,c)<<"\n";
    }

    return 0;
}