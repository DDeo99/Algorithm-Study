// BOJ 11866번 요세푸스 문제 0

#include <iostream>
#include <queue>
#include <vector>

using namespace std;



class circularQueue
{
    private:
        int front;
        int rear;
        vector<int> q;
        int MAX;
    public:
        circularQueue(int maxSize) : front(0),rear(0),MAX(maxSize+1)
            {
                q.resize(MAX);
            }

        void enqueue(int input)
        {
            if ((rear + 1) % MAX == front)
        {
            return;
        }
           q[rear]=input;
           rear=(rear+1)%MAX;
        }

        void dequeue()
        {
            if(rear==front)
            {
                return;
            }

            front=(front+1)%MAX;
        }

        bool isEmpty()
        {
            return front==rear;
        } 

        bool isFull()
        {   
            return (rear+1)%MAX==front;
        }


        int ffront()
        {
            return q[front];
        }

        int rrear()
        {
            return q[rear];
        }
        
};

int main()
{
    int N,K;

    cin>>N>>K;

    circularQueue cq(N);
    vector<int> result;

    int cnt=0;

    for(int i=1;i<=N;i++)
    {
        cq.enqueue(i);
    }

    while(!cq.isEmpty())
    {
        cnt++;

        if(cnt%(K)==0)
        {
            result.push_back(cq.ffront());
            cq.dequeue();
        }

        else
        {
            int front= cq.ffront();
            cq.dequeue();
            cq.enqueue(front);
        }
    }

    cout<<"<";
    for(int i=0;i<result.size()-1;i++)
    {
        cout<< result.at(i) <<", ";
    }
    cout<<result[result.size()-1];
    cout<<">";

    return 0;
}