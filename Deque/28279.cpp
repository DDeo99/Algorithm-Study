// BOJ 28279 덱 2

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Deque
{
private:
    vector<int> deque;
    int head;
    int tail;

public:
    Deque(int size) : deque(2*size+1), head(size), tail(size) {}
    Deque() {}

    void push_front(int num) 
    {
        deque[--head] = num;
    }

    void push_rear(int num)
    {
      deque[tail++] = num;
    }

    void pop_front()
    {
        head++;
    }

    void pop_rear()
    {
        tail--;
    }

    int front()
    {
        return deque[head];
    }

    int rear()
    {
        return deque[tail-1];
    }

    int num()
    {
        return tail-head;
    }

    bool isEmpty()
    {
        if(tail<=head)
        {
            return 1;
        }

        else
        {
            return 0;
        }
    }

    int command3()
    {
        if(!isEmpty())
        {
            int res = front();
            head++;
            return res;
            
        }
        else
        {
            return -1;
        }
    }

    int command4()
    {
        if(!isEmpty())
        {
            int res=rear();
            tail--;
            return res;
        }
        else
        {
            return -1;
        }
    }

    int command7()
    {
        if(!isEmpty())
        {
            return front();
        }
        else
        {
            return -1;
        }
    }

    int command8()
    {
        if(!isEmpty())
        {
            return rear();
        }
        else
        {
            return -1;
        }
    }   
};

int main() 
{
    int N;
    scanf("%d",&N);

    Deque dq(N);

    for(int i=0;i<N;i++)
    {
        int num;
        scanf("%d",&num);
      

        if(num == 1)
        {
            int num2;
            scanf("%d",&num2);
            dq.push_front(num2);
        }

        else if(num == 2)
        {
            int num2;
            scanf("%d",&num2);
            dq.push_rear(num2);
        }
       
        else if(num == 3)
        {
            printf("%d\n",dq.command3());
        }

        else if(num == 4)
        {
            printf("%d\n",dq.command4());
        }

        else if(num == 5)
        {
            printf("%d\n",dq.num());
        }

        else if(num == 6)
        {
            printf("%d\n",dq.isEmpty());
        }

        else if(num == 7)
        {
            printf("%d\n",dq.command7());
        }

        else if(num == 8)
        {
            printf("%d\n",dq.command8());
        }
    }
   
    return 0;
}