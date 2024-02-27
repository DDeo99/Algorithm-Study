// BOJ 백준 5639번 이진검색트리

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <unordered_map>

using namespace std;

int nodes[10001];

// 입력은 inorder된 순서
// root를 기준으로 root보다 작은 값은 left, 큰 값은 right
// postOrder 돌리고 root를 다음 idx로 이동하여 반복

void postOrder(int s, int e)
{
    if(s>=e)
        return;

    int root=nodes[s];
    int newS=s+1;

    while(nodes[newS]<root && newS<e)
    {
        newS++; // 처음으로 root보다 큰 값일 때의 idx
    }

    postOrder(s+1,newS);
    postOrder(newS,e);
    cout<<root<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int num;
    int idx=0;
    while(cin>>num)
    {
       nodes[idx++]=num;
    }

    postOrder(0,idx);

    return 0;
}