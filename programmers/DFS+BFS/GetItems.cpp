#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int map[102][102];
int cnt[102][102];
bool visited[102][102];
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 102*102+1;
    
    // 사각형 둘레를 1로
    for (int i=0;i<rectangle.size();i++)
    {
        for (int j=0;j<rectangle[i].size();j++)
        {
            // 사각형 좌표를 *2
            rectangle[i][j] = rectangle[i][j] * 2;
        }
        int y1 = rectangle[i][0];
        int x1 = rectangle[i][1];
        int y2 = rectangle[i][2];
        int x2 = rectangle[i][3];
        
        for (int y=y1;y<=y2;y++)
        {
            for (int x=x1;x<=x2;x++)
            {
                map[y][x] = 1;
            }
        }
    }
    
    // 사각형 내부는 0으로
    for (int i=0;i<rectangle.size();i++)
    {
        int y1 = rectangle[i][0];
        int x1 = rectangle[i][1];
        int y2 = rectangle[i][2];
        int x2 = rectangle[i][3];
        
        for (int y=y1+1;y<y2;y++)
        {
            for (int x=x1+1;x<x2;x++)
            {
                map[y][x] = 0;
            }
        }
    }
    
    queue<pair<int,int>> q;
    q.push({characterX*2,characterY*2});
    cnt[characterX*2][characterY*2]=1;
    
    while(!q.empty())
    {
        pair<int,int> cur=q.front();
        q.pop();
        visited[cur.first][cur.second]=1;
        
        for(int i=0;i<4;i++)
        {
            int ny=cur.first+dy[i];
            int nx=cur.second+dx[i];
            
            if(ny<0 || ny>=102 || nx<0 || nx>=102)
                continue;
            
            if(visited[ny][nx])
                continue;
            
            if(map[ny][nx]==0)
                continue;
            
            visited[ny][nx]=1;
            q.push({ny,nx});
            cnt[ny][nx]=cnt[cur.first][cur.second]+1;
            
            if(ny==itemX*2 && nx==itemY*2)
            {
                answer=cnt[ny][nx]/2;
                break;
            }
        }
    }
    
    return answer;
}