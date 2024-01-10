// BOJ 백준 1037번 약수
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    scanf("%d",&N);

    vector<int> divisor;

    int res;

    /*
    int num;
    while(scanf("%d",&num)==1)
    {
        divisor.push_back(num);
    }
    */

    for(int i=0;i<N;i++)
    {
        int num;
        scanf("%d",&num);
        divisor.push_back(num);
    }

    sort(divisor.begin(),divisor.end());

    if(divisor.size()!=1)
    {
        int num1=divisor[0];
        int num2=divisor[divisor.size()-1];
        res=num1*num2;  
    }

    else
    {
        res=divisor[0]*divisor[0];
    }

    printf("%d",res);



    return 0;
}