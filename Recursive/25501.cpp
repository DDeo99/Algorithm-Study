// BOJ 백준 25501번 재귀의 귀재

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int cnt=0;

int recursion(const char *s, int l, int r)
{
    cnt++;

    if(l >= r)
        return 1;

    else if(s[l] != s[r])
        return 0;

    else
        return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s)
{
    return recursion(s, 0, strlen(s)-1);
}

int main()
{
    int T;
    scanf("%d",&T);

    for(int i=0;i<T;i++)
    {
        char s[1001]; 
        scanf("%s",s);
        int res=isPalindrome(s);
        printf("%d %d\n",res,cnt);
        cnt=0;
    }

    return 0;
}
/*
int recursion(string s, int l, int r)
{
    cnt++;

    if(l>=r)
        return 1;
    
    else if(s[l]!=s[r])
        return 0;

    else
        return recursion(s,l+1,r-1);
}

int isPalindrome(string s)
{
    return recursion(s,0,s.length()-1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;

    for(int i=0;i<T;i++)
    {
        string s;
        cin>>s;
        cout<<isPalindrome(s)<<" "<<cnt<<endl;
        cnt=0;
    }

    return 0;
}
*/