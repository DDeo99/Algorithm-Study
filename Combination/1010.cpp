// BOJ 백준 1010번 다리 놓기

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

int combination(int M, int N) 
{
    //M+1 행, N+1 열, 0으로 초기화
    vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));

    for (int i = 0; i <= M; i++)
     {
        for (int j = 0; j <= min(i, N); j++) 
        {
            if (j == 0 || j == i) 
            {
                dp[i][j] = 1;
            }
            else 
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }

    return dp[M][N];
}

int main() 
{
    int T; 
    scanf("%d",&T);

    for (int i = 0; i < T; i++) {
        int N, M; 
        scanf("%d %d",&N, &M);

        printf("%d\n",combination(M,N));
    }

    return 0;
}

/*
int combination(int N, int M)
{
    if(N==0 || N==M)
    {
        return 1;
    }

    else
    {
        return combination(N-1,M-1)+combination(N,M-1);
    }
}

int main()
{
    int T, N, M;
    int res=0;

    scanf("%d",&T);
    
    for(int i=0;i<T;i++)
    {
        scanf("%d %d",&N, &M);

        printf("%d\n",combination(N,M));

    }

    return 0;
}
*/