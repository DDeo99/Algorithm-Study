// BOJ 백준 15961번 회전초밥

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

long long N;
int d,k,c;

vector<int> susi;
vector<int> category;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //접시 수, 초밥 가지수, 연속해서 먹는 접시 수, 쿠폰 번호
    cin>>N>>d>>k>>c;

    for(int i=0;i<N;i++)
    {
        int num;
        cin>>num;
        susi.push_back(num);
    }

    category.resize(d+1,0);

    // idx -> %N 해서 사용
    // 모두 다른 k개 연속으로 먹음 + c 받음 -> 가능하면 max
    // k개 연속으로 먹음 + c 받음, 그러나 중복된 스시 먹음

    int start=0;
    int end=0;
    int eatCnt=0;
    int kCnt=0;
    int ans=0;

    while(start<N)
    {
        if(kCnt<k)
        {
            if(category[susi[end%N]]==0)
            {
                category[susi[end%N]]++;
                eatCnt++;
                end=(end%N)+1;
                kCnt++;
            }
            else
            {
                category[susi[end%N]]++;
                end=(end%N)+1;
                kCnt++;
            }
        }

        else if(kCnt==k)
        {
            if(category[c]==0)
            {
                category[c]++;
                eatCnt++;
            }

            ans=max(ans,eatCnt);

            if(category[susi[start%N]]==1)
            {
                eatCnt--;
                category[susi[start%N]]--;
                start++;
                kCnt--;
            }
            else if(category[susi[start%N]]>1)
            {
                category[susi[start%N]]--;
                start++;
                kCnt--;
            }

        }

    }

    cout<<ans;

    return 0;
}