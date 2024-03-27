//BOJ 백준 14500번 테트로미노
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int N,M;
vector<vector<int>> map;
vector<vector<bool>> checked;
int ans=0;

int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};

void dfs(int y, int x, int level, int sum)
{
    if(level==4)
    {
        ans=max(sum,ans);
        return;
    }
    checked[y][x]=1;
    // 4칸 이어서
    for(int i=0;i<4;i++)
    {
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny<1 || ny>N || nx<1 || nx>M)
            continue;
        if(checked[ny][nx]==0)
        {
            checked[ny][nx]=1;
            dfs(ny,nx,level+1,sum+map[ny][nx]);
            checked[ny][nx]=0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N>>M;
    map.resize(N+1,vector<int>(M+1));
    checked.resize(N+1,vector<bool>(M+1));

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            cin>>map[i][j];
        }
    }

    for(int y=1;y<=N;y++)
    {
        for(int x=1;x<=M;x++)
        {
            dfs(y,x,1,map[y][x]);
            checked[y][x]=0;
            // 특수 케이스
            // ㅓ
            if(x - 1 >= 1 && y - 1 >= 1 && y + 1 <= N)
                ans = max(ans, map[y][x-1] + map[y-1][x] + map[y][x] + map[y+1][x]);
            // ㅏ
            if(x + 1 <= M && y - 1 >= 1 && y + 1 <= N)
                ans = max(ans, map[y][x+1] + map[y-1][x] + map[y][x] + map[y+1][x]);
            // ㅗ
            if(x - 1 >= 1 && y - 1 >= 1 && x + 1 <= M)
                ans = max(ans, map[y][x-1] + map[y-1][x] + map[y][x] + map[y][x+1]);
            // ㅜ
            if(x - 1 >= 1 && y + 1 <= N && x + 1 <= M)
                ans = max(ans, map[y][x-1] + map[y+1][x] + map[y][x] + map[y][x+1]);
        }
    }

    cout<<ans;

    return 0;
}