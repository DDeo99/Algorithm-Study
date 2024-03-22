// BOJ 백준 2407번 조합 (string으로 덧셈)
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

string cache[101][101];
int n,m;

string add(string n1, string n2)
{
    string res="";

    int sum=0;

    while(!n1.empty()||!n2.empty()||sum)
    {
        if(!n1.empty())
        {
            sum+=n1.back()-'0';
            n1.pop_back();
        }
        if(!n2.empty())
        {
            sum+=n2.back()-'0';
            n2.pop_back();
        }
        res.push_back((sum%10)+'0');
        sum/=10;
    }
    reverse(res.begin(),res.end());
    return res;
}

string cb(int n, int m)
{

    if(m==0)
    {
        return cache[n][m]="1";
    }

    else if(n==m)
    {
        return cache[n][m]="1";
    }

    if(cache[n][m]!="")
        return cache[n][m];

    else
    {
        return cache[n][m]=add(cb(n-1,m),cb(n-1,m-1));
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>m;

    cout<<cb(n,m);
    return 0;
}