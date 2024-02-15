// BOJ 백준 1149번 RGB거리

#include <iostream>
#include <vector>

using namespace std;

int N;
int R = 1;
int G = 2;
int B = 3;
int cost[4][4];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N;

    for(int i=1;i<N+1;i++)
    {
        for(int j=1;j<N+1;j++)
        {
            cin>>cost[i][j];
        }
    }


    return 0;
}