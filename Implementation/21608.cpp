// BOJ 백준 21608번 상어 초등학교

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int N;
vector<vector<int>> seat;
vector<vector<int>> love;
vector<vector<int>> nearEmpty;
vector<vector<int>> nearLove;

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N;

    seat.resize(N+1,vector<int>(N+1,0));
    love.resize(N*N+1);

    for(int i=0;i<N*N;i++)
    {
        
        nearEmpty.resize(N+1,vector<int>(N+1,0));
        nearLove.resize(N+1,vector<int>(N+1,0));

        int student;
        cin>>student;

        for(int j=0;j<4;j++)
        {
            int friends;
            cin>>friends;
            love[student].push_back(friends);
        }
        
        int max=-1;

        pair<int,int> studentSeat={1,1};
        int ecnt,lcnt;

        for(int n=1;n<N+1;n++)
        {
            for(int m=1;m<N+1;m++)
            {   
                //ecnt=0;lcnt=0;
                nearEmpty[n][m]=0;
                nearLove[n][m]=0;
                if(seat[n][m]!=0)
                    continue;
                // 현재 자리 비어있음
                else if(seat[n][m]==0)
                {
                    for(int k=0;k<4;k++)
                    {
                        int nx=n+dx[k];
                        int ny=m+dy[k];
                        if(nx>=1 && nx<=N && ny>=1 && ny<=N)
                        {
                            // 인접 자리가 비어있음
                            if(seat[nx][ny]==0)
                            {
                                //ecnt++;
                                nearEmpty[n][m]++;
                            }
                            // 인접 자리 누가 있음
                           
                            for(int l=0;l<4;l++)
                            {
                                // 인접 자리가 좋아하는 사람이면
                                if(seat[nx][ny]==love[student][l])
                                {
                                    //lcnt++;
                                    nearLove[n][m]++;
                                }
                            }  
                        }
                    }
                }
              

                //nearEmpty[n][m]=ecnt;
                //nearLove[n][m]=lcnt;

                if(max<nearLove[n][m])
                {
                    max=nearLove[n][m];
                    studentSeat={n,m};
                }

                else if(max==nearLove[n][m])
                {
                    if(nearEmpty[n][m]>nearEmpty[studentSeat.first][studentSeat.second])
                    {
                        studentSeat.first=n;
                        studentSeat.second=m;
                    }

                    else if(nearEmpty[n][m]==nearEmpty[studentSeat.first][studentSeat.second])
                    {
                        if(n<studentSeat.first)
                        {
                            studentSeat.first=n;
                            studentSeat.second=m;
                        }
                        else if(n==studentSeat.first)
                        {
                            if(m<studentSeat.second)
                            {
                                studentSeat.first=n;
                                studentSeat.second=m;
                            }
                        }
                    }
                }
            }
        }
       
        seat[studentSeat.first][studentSeat.second]=student;
    }
   
    int ans=0;


    for (int i = 1; i <= N; ++i) 
    {
        for (int j = 1; j <= N; ++j) 
        {
            cout << seat[i][j] << " ";
        }
        cout << endl; // 한 행 출력 후 줄 바꿈
    }

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            int satisfy=0;
            for(int k=0;k<4;k++)
            {
                if(i+dx[k]>=1 && i+dx[k]<=N && j+dy[k]>=1 && j+dy[k]<=N)
                {
                    for(int l=0;l<love[seat[i][j]].size();l++)
                    {
                        if(seat[i+dx[k]][j+dy[k]]==love[seat[i][j]][l])
                        {
                            satisfy++;
                            break;
                        }
                    }
                }
            }
            if(satisfy==1)
                ans+=1;
            else if(satisfy==2)
                ans+=10;
            else if(satisfy==3)
                ans+=100;
            else if(satisfy==4)
                ans+=1000;
        }
    }
    cout<<ans;
    return 0;
}