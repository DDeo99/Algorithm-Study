// 백준 BOJ 4920번 테트리스 게임
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int TC=1;

    while(1)
    {
        int N;
        vector<vector<int>> map;
        int ans=-987654321;

        cin>>N;

        if(!N)
            break;

        map.resize(N,vector<int> (N));

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin>>map[i][j];
            }
        }

        int temp=0;

        // ㅣ
        for(int i=0;i+3<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                temp=0;
                temp=map[i][j]+map[i+1][j]+map[i+2][j]+map[i+3][j];
                ans=max(ans,temp);
            }
        }

        // ㅡ
        for(int i=0;i<N;i++)
        {
            for(int j=0;j+3<N;j++)
            {
                temp=0;
                temp=map[i][j]+map[i][j+1]+map[i][j+2]+map[i][j+3];
                ans=max(ans,temp);
            }
        }

        // ㅁㅁ
        //   ㅁㅁ
        for(int i=0;i+1<N;i++)
        {
            for(int j=0;j+2<N;j++)
            {
                temp=0;
                temp=map[i][j]+map[i][j+1]+map[i+1][j+1]+map[i+1][j+2];
                ans=max(ans,temp);
            }
        }

        //   ㅁ
        // ㅁㅁ
        // ㅁ
        for(int i=0;i+2<N;i++)
        {
            for(int j=0;j+1<N;j++)
            {
                temp=0;
                temp=map[i][j+1]+map[i+1][j]+map[i+1][j+1]+map[i+2][j];
                ans=max(ans,temp);
            }
        }

        // ㅁㅁㅁ
        //     ㅁ
        for(int i=0;i+1<N;i++)
        {
            for(int j=0;j+2<N;j++)
            {
                temp=0;
                temp=map[i][j]+map[i][j+1]+map[i][j+2]+map[i+1][j+2];
                ans=max(ans,temp);
            }
        }

        for(int i=0;i+1<N;i++)
        {
            for(int j=0;j+2<N;j++)
            {
                temp=0;
                temp=map[i][j]+map[i+1][j]+map[i+1][j+1]+map[i+1][j+2];
                ans=max(ans,temp);
            }
        }

        for(int i=0;i+2<N;i++)
        {
            for(int j=0;j+1<N;j++)
            {

                temp=0;
                temp=map[i+2][j]+map[i][j+1]+map[i+1][j+1]+map[i+2][j+1];
                ans=max(ans,temp);
            }
        }

        for(int i=0;i+1<N;i++)
        {
            for(int j=0;j+2<N;j++)
            {
                temp=0;
                temp=map[i][j]+map[i+1][j]+map[i+1][j+1]+map[i+1][j+2];
                ans=max(ans,temp);
            }
        }

        //ㅓ
        for (int i = 0; i < N - 2; i++) 
        {
            for (int j = 0; j < N - 1; j++) 
            {
                temp=0;
                temp = map[i + 1][j] + map[i + 1][j + 1] + map[i][j + 1] + map[i + 2][j + 1];
                ans=max(ans,temp);
            }
        }
        //ㅗ
        for (int i = 0; i < N - 1; i++)
        {
            for (int j = 0; j < N - 2; j++) 
            {
                temp=0;
                temp = map[i + 1][j] + map[i + 1][j + 1] + map[i][j + 1] + map[i + 1][j + 2];
                ans=max(ans,temp);
            }
        }
        //ㅜ
        for (int i = 0; i < N - 1; i++) 
        {
            for (int j = 0; j < N - 2; j++) 
            {
                temp=0;
                temp = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1];
                ans=max(ans,temp);
            }
        }
        //ㅏ
        for (int i = 0; i < N - 2; i++) 
        {
            for (int j = 0; j < N - 1; j++) 
            {
                temp=0;
                temp = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j + 1];
                ans=max(ans,temp);
            }
        }
        //ㅁ
        for (int i = 0; i < N - 1; i++) 
        {
            for (int j = 0; j < N - 1; j++) 
            {
                temp=0;
                temp = map[i][j] + map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1];
                ans=max(ans,temp);
            }
        }
 
        cout<<TC<<". "<<ans<<"\n";

        TC++;
    
    }
    return 0;
}