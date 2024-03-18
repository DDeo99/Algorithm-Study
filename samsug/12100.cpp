// BOJ 백준 12100번 2048(Easy)
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
vector<vector<int>> matrix;
int maxV=-1;
int ans=-1;
/*
void move(int type)
{
    queue<int> q;

    //상
    if(type==0)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(matrix[j][i])
                    q.push(matrix[j][i]);
                matrix[j][i]=0;
            }
            int idx=0;
            while(!q.empty())
            {
                int num=q.front();
                q.pop();

                if(matrix[idx][i]==0)
                    matrix[idx][i]=num;
                else if(matrix[idx][i]==num)
                {
                    matrix[idx][i]*=2;
                    idx++;
                }
                else
                {
                    matrix[idx+1][i]=num;
                    idx++;
                }
            }

        }
    }    

    // 하
    if(type==1)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(matrix[N-j-1][i])
                    q.push(matrix[N-j-1][i]);
                matrix[N-j-1][i]=0;
            }
            int idx=N-1;
            while(!q.empty())
            {
                int num=q.front();
                q.pop();

                if(matrix[idx][i]==0)
                    matrix[idx][i]=num;
                else if(matrix[idx][i]==num)
                {
                    matrix[idx][i]*=2;
                    idx--;
                }
                else
                {
                    matrix[idx-1][i]=num;
                    idx--;
                }
            }

        }
    }    

    //좌
    if(type==2)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(matrix[i][j])
                    q.push(matrix[i][j]);
                matrix[i][j]=0;
            }
            int idx=0;
            while(!q.empty())
            {
                int num=q.front();
                q.pop();

                if(matrix[i][idx]==0)
                    matrix[i][idx]=num;
                else if(matrix[i][idx]==num)
                {
                    matrix[i][idx]*=2;
                    idx++;
                }
                else
                {
                    matrix[i][idx+1]=num;
                    idx++;
                }
            }

        }
    }    

    // 우
    if(type==3)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(matrix[i][N-j-1])
                    q.push(matrix[i][N-j-1]);
                matrix[i][N-j-1]=0;
            }
            int idx=N-1;
            while(!q.empty())
            {
                int num=q.front();
                q.pop();

                if(matrix[i][idx]==0)
                    matrix[i][idx]=num;
                else if(matrix[i][idx]==num)
                {
                    matrix[i][idx]*=2;
                    idx--;
                }
                else
                {
                    matrix[i][idx-1]=num;
                    idx--;
                }
            }

        }
    }    
}

void solve(int cnt)
{
    if(cnt==5)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                maxV=max(maxV,matrix[i][j]);
            }
        }
        return;
    }

    vector<vector<int>> temp=matrix;

    for(int i=0;i<4;i++)
    {
        move(i);
        solve(cnt+1);
        matrix=temp;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N;

    matrix.resize(N,vector<int>(N));

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>matrix[i][j];
        }
    }

    solve(0);

    cout<<maxV;

    return 0;
}
*/

void move(int mode)
{
    queue<int> q;
    // 상
    if(mode==0)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(matrix[j][i])
                {
                    q.push(matrix[j][i]);
                    matrix[j][i]=0;
                }
            }
        

        int idx=0;
        
            while(!q.empty())
            {
                if(matrix[idx][i]==0)
                {
                    matrix[idx][i]=q.front();
                    q.pop();
                }

                else
                {
                    if(matrix[idx][i]==q.front())
                    {
                        matrix[idx][i]*=2;
                        q.pop();
                        idx++;
                    }

                    else
                    {
                        matrix[idx+1][i]=q.front();
                        q.pop();
                        idx++;
                    }
                }
            }
        }
    }

    // 하
    else if(mode==1)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(matrix[N-j-1][i])
                {
                    q.push(matrix[N-j-1][i]);
                    matrix[N-j-1][i]=0;
                }
            }
          
            int idx=N-1;
            while(!q.empty())
            {    
                if(matrix[idx][i]==0)
                {
                    matrix[idx][i]=q.front();
                    q.pop();
                }

                else
                {
                    if(matrix[idx][i]==q.front())
                    {
                        matrix[idx][i]*=2;
                        q.pop();
                        idx--;
                    }

                    else
                    {
                        matrix[idx-1][i]=q.front();
                        q.pop();
                        idx--;
                    }
                }
                
            }
        }
    }

    // 좌
    else if(mode==2)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(matrix[i][j])
                {
                    q.push(matrix[i][j]);
                    matrix[i][j]=0;
                }
            }
          

            int idx=0;
            while(!q.empty())
            {
                
                if(matrix[i][idx]==0)
                {
                    matrix[i][idx]=q.front();
                    q.pop();
                }

                else
                {
                    if(matrix[i][idx]==q.front())
                    {
                        matrix[i][idx]*=2;
                        q.pop();
                        idx++;
                    }

                    else
                    {
                        matrix[i][idx+1]=q.front();
                        q.pop();
                        idx++;
                    }
                }
                
            }
        }
    }

    // 우
    else if(mode==3)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(matrix[i][N-j-1])
                {
                    q.push(matrix[i][N-j-1]);
                    matrix[i][N-j-1]=0;
                }
            }
          

            int idx=N-1;
            while(!q.empty())
            {
                
                if(matrix[i][idx]==0)
                {
                    matrix[i][idx]=q.front();
                    q.pop();
                }

                else
                {
                    if(matrix[i][idx]==q.front())
                    {
                        matrix[i][idx]*=2;
                        q.pop();
                        idx--;
                    }

                    else
                    {
                        matrix[i][idx-1]=q.front();
                        q.pop();
                        idx--;
                    }
                }
            }
        }
    }
}

void dfs(int level)
{
    if(level==5)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                maxV=max(maxV,matrix[i][j]);
            }
        }
        return;
    }

    vector<vector<int>> temp=matrix;

    for(int i=0;i<4;i++)
    {
        move(i);
        dfs(level+1);
        matrix=temp;
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N;
    matrix.resize(N,vector<int>(N,0));

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>matrix[i][j];
        }
    }

    dfs(0);

    cout<<maxV;

    return 0;
}