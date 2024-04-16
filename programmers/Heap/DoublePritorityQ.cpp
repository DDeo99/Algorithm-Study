#include <string>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    priority_queue<int,vector<int>,less<int>> Mpq;
    priority_queue<int,vector<int>,greater<int>> mpq;
    int cnt=0;
    
    for(int i=0;i<operations.size();i++)
    {
        stringstream ss(operations[i]);
        string op;
        int num;
        ss >> op >> num;
        
        if(op=="I")
        {
            mpq.push(num);
            Mpq.push(num);
            cnt++;
        }
        else if(op=="D" && cnt>0)
        {
            if(num==-1)
            {
                mpq.pop();
                cnt--;
            }
            else if(num==1)
            {
                Mpq.pop();
                cnt--;
            }
        }
        if(cnt==0)
        {
            while(!Mpq.empty()){
                Mpq.pop();
            }
            while(!mpq.empty()){
                mpq.pop();
            }
        }
        
        while(!Mpq.empty() && !mpq.empty() && mpq.top() > Mpq.top()) 
        {
            int maxTop = Mpq.top(); Mpq.pop();
            int minTop = mpq.top(); mpq.pop();
            Mpq.push(minTop);
            mpq.push(maxTop);
        }
        
    }
    
    int minNum=0;
    int maxNum=0;
    if(cnt>0)
    {
        maxNum=Mpq.top();
        minNum=mpq.top();
    }
    
    answer.push_back(maxNum);
    answer.push_back(minNum);
    
    return answer;
}