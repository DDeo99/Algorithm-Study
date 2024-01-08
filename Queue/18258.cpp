// BOJ 18258번 큐 2

#define _CRT_NO_SECURE_WARNINGS

#include <iostream>
#include <string>
#include <limits>
#include <vector>

using namespace std;

class queue 
{
    private:
        vector<int> q;
        int frontIdx, rearIdx;
    
    public:
        queue():
            frontIdx(0), rearIdx(0)
            {

            }
        
        void push(int input)
        {
            q.push_back(input);
            rearIdx++;
        }

        int pop()
        {
            if(!empty())
            {
                frontIdx++;
                return q[frontIdx-1];
            }
            else
            {
                return -1;
            }
        }

        int size()
        {
            if(!empty())
            {
                return (rearIdx-frontIdx);
            }
            else
            {
                return 0;
            }
        }

        int empty()
        {   
            return (rearIdx-frontIdx)==0 ? 1 : 0;
        }

        int front()
        {
            if(!empty())
            {
                return q[frontIdx];
            }
            else
            {
                return -1;
            }
        }

        int back()
        {
            if(!empty())
            {
                return q[rearIdx-1];
            }
            else
            {
                return -1;
            }
        }
};

int main()
{
    cin.tie(nullptr); 
    ios_base::sync_with_stdio(false);

    int N;
    cin>>N;

    queue q;

    for (int i=0; i<N; i++)
    {
        string cmd;
        cin >> cmd;

        if(cmd == "push")
        {
            int num;
            cin >> num;
            q.push(num);
        }

        else if(cmd == "pop")
        {
            printf("%d\n",q.pop());
        }

        else if(cmd == "size")
        {
            printf("%d\n",q.size());
        }

        else if(cmd == "empty")
        {
            printf("%d\n", q.empty());
        }

        else if(cmd == "front")
        {
            printf("%d\n",q.front());
        }

        else if(cmd == "back")
        {
            printf("%d\n",q.back());
        }
    }

    return 0;
}