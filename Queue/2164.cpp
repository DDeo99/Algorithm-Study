// BOJ 2164번 카드 2

#include <iostream>
#include <queue>

using namespace std;

int main()
{

    cin.tie(nullptr); 
    ios_base::sync_with_stdio(false);

    int N;
    cin>>N;

    queue<int> q;

    for(int i=1;i<=N;i++)
    {
        q.push(i);
    }

    while(q.size()>1)
    {
        q.pop();
        if(q.size()>1)
        {
            int bottom = q.front();
            q.pop();
            q.push(bottom);
        }
    }

    cout<<q.front()<<endl;



    return 0;
}