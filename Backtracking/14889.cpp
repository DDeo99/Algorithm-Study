//BOJ 백준 14889번 스타트와 링크

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
int level;
vector<bool> flag;
int ans=-1;


void stat(vector<vector<int>> &S, int idx, int cnt)
{
    vector<int> start; // 스타트 팀원의 인덱스값
    vector<int> link; // 링크팀 팀원의 인덱스값
    int start_score = 0;
    int link_score = 0;
    if(cnt == level)
    {
        for(int i = 0; i < N; i++)
        {
            // 팀 구성
            if(flag[i] == true) 
                start.push_back(i);
            else 
                link.push_back(i);
        }

        //능력치 덧셈
        for(int i = 0; i < level; i++)
            for(int j = 0; j < level; j++)
            {
                if(i!=j)
                {
                    start_score += S[start[i]][start[j]];
                    link_score += S[link[i]][link[j]];
                }
            } 

        int dif = abs(start_score - link_score);

        if(dif < ans || ans==-1)
        {
            ans = dif;
        }

        return;
    }

    for(int i = idx; i < N; i++)
    {
        if(!flag[i])
        {
            flag[i] = true;
            stat(S,i,cnt+1);
            flag[i] = false;
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    //팀 인원 = N/2
    level=N/2;

    vector<vector<int>> S(N, vector<int>(N,0));

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>S[i][j];
        }
    }

    flag.resize(N,0);

    stat(S,0,0);
    cout<<ans;

    return 0;
}

/*
void stat(vector<vector<int>> &S, int starting, int cnt)
{
    
    if(cnt==level)
    {
        int idx1=0;
        int idx2=0;
        for(int i=0;i<N;i++)
        {
            if(flag[i])
            {
                start[idx1]=i;
                idx1++;
            }
            else
            {
                link[idx2]=i;
                idx2++;
            }
        }

        int sum_start=0;
        int sum_link=0;

        for(int i=0;i<level-1;i++)
        {
            for(int j=i+1;j<level;j++)
            {
                sum_start+=S[start[i]][start[j]] + S[start[j]][start[i]];
                sum_link+=S[link[i]][link[j]]+S[link[j]][link[i]];
            }
        }

        int dif=abs(sum_start-sum_link);

        if((dif < ans) || (ans==-1))
        {
            ans=dif;
        }

    }

    else
    {
        for(int i=starting;i<N;i++)
        {
            if(!flag[i])
            {
                flag[i]=true;
                stat(S,i+1,cnt+1);
                flag[i]=false;
            }
        }
    }
}
*/