// BOJ 2346번 풍선 터뜨리기

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;


int main() {

    int N;
    scanf("%d",&N);

    vector<int> cdq;

    for(int i=0;i<N;i++)
    {
        int n;
        scanf("%d",&n);
        cdq.push_back(n);
    }

    int idx=0;

    for(int i=0;i<N;i++)
    {
        printf("%d ",idx+1);

        if(i==N-1)
        {
            break;
        }

        int distance=cdq[idx];

        cdq[idx]=0;

        if(distance>0) 
        {
           for(int i=0;i<distance;i++)
           {
          
                idx=(idx+1)%N;

                if(cdq[idx]==0)
                {
                    i--;
                }
           }
        }

        else
        {
            distance*=-1;
            
            for(int i=0;i<distance;i++)
            {
          
                idx=(idx-1+N)%N;

                if(cdq[idx]==0)
                {
                    i--;
                }
            }
        }
    }

    return 0;
}

/*
int main() {
    
    int N;
    scanf("%d",&N);

    vector<int> cdq(N);
    vector<bool> popped(N,false);

    for(int i=0;i<N;i++)
    {
        scanf("%d",&cdq[i]);
    }

    int idx=0;

    for(int i=0;i<N;i++) 
    {
        printf("%d ",idx+1);

        int distance = cdq[idx];
        popped[idx]=true;

        if(i==N-1) break;

        if(distance>0) 
        {
            while(distance>0)
            {
                idx=(idx+1)%N;

                if(!popped[idx])
                {
                    distance--;
                }
            }
        }

        else
        {
            while(distance<0)
            {
                idx=(idx-1+N)%N;

                 if(!popped[idx])
                {
                    distance++;
                }
            }
        }

    }
}
*/