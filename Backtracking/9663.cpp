// BOJ 백준 9663번 N-Queen

#include <iostream>
#include <vector>

using namespace std;

int cnt=0;

/**
 * queen은 한 행에 무조건 하나, 열에도 무조건 하나 -> 일차원 벡터 사용
 * i는 x좌표, queens[i]는 y좌표 -> queens[1]=2 는 2번째 행 3번째 열에 퀸 존재
 * 
*/
bool isPossible(vector<int> &queens, int x, int y)
{
    for(int i=0;i<x;i++)
    {
        // queens[x] == queems[i] -> 같은 열에 queen 존재 , abs(y-queens[i])==abs(x-i) -> 같은 대각선에 queen 존재
        if(queens[x] == queens[i] || abs(y-queens[i])==abs(x-i))
        {
            return false;
        }
    }
    return true;
}


void queen(vector<int> &queens, int N, int x)
{
    if(x == N)
    {
        cnt++;
        return;
    }

    for(int y=0;y<N;y++)
    {
        queens[x]=y;
        if(isPossible(queens,x,y))
        {
            queen(queens,N,x+1);
        }
    }   
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> queens(N,0);
    int start_x=0;

    queen(queens,N,start_x);
    cout<<cnt;
    return 0;
}