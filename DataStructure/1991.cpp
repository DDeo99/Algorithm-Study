// BOJ 백준 1191번 트리순회

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

vector<pair<char,char>> tree;

int N;

void pre(char start)
{
    if(start!='.')
    {
        cout<<start;
        pre(tree[start-'A'].first);
        pre(tree[start-'A'].second);
    }
    else
        return ;
}

void in(char start)
{
    if(start!='.')
    {
        in(tree[start-'A'].first);
        cout<<start;
        in(tree[start-'A'].second);
    }
    else
        return ;
}

void post(char start)
{
    if(start!='.')
    {
        post(tree[start-'A'].first);
        post(tree[start-'A'].second);
        cout<<start;
    }
    else
        return ;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N;
    tree.resize(N);

    for(int i=0;i<N;i++)
    {
        char c,l,r;
        cin>>c>>l>>r;
        if(c!='.')
        {
            tree[c-'A'].first=l;
            tree[c-'A'].second=r;
        }
    }

    pre('A');
    cout<<"\n";
    in('A');
    cout<<"\n";
    post('A');
    

    return 0;
}