// BOJ 28278 Ω∫≈√2

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack<int> v;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    scanf("%d",&N);
    
    vector<int> results;

    for(int i=0;i<N;i++)
    {
        int num=0;
        scanf("%d",&num);

        if (num==1)
        {
            int x;
            scanf("%d",&x);
            v.push(x);
        }

        else if(num==2)
        {
            if (v.empty())
            {
                results.push_back(-1);
            }
            else
            {
                results.push_back(v.top());
                v.pop();
            }
        }

        else if(num==3)
        {
            results.push_back(v.size());
        }

        else if(num==4)
        {
        results.push_back(v.empty() ? 1 : 0);
        }

        else if(num==5)
        {
            results.push_back(v.empty() ? -1 : v.top());
        }
    } 

  for (int res : results)
    {
        printf("%d\n",res);
    }


    return 0;
}