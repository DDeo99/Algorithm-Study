#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
int ans;

// 이차원 배열의 x,y -> 일차원 배열의 idx, value로 변경, value!=0 -> flag의 true

vector<int> queens;

bool isPossible(int x, int y)
{
    for(int i=0;i<x;i++)
    {

        if(y==queens[i] || (abs(i-x)==abs(queens[i]-y)))
        {
            return false;
        }
        
    }

    return true;
}

void queen(int cnt)
{
    if(cnt==N)
    {
        ans++;
        return;
    }

    for(int i=0;i<N;i++)
    {
        queens[cnt]=i;

        if(isPossible(cnt,queens[cnt]))
        {
            queen(cnt+1);
            queens[cnt]=-1;
        }
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N;

    queens.resize(N,-1);

    queen(0);

    cout<<ans;
    return 0;
}
