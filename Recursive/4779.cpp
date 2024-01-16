//BOJ 백준 4779번 칸토어 집합

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void separate(vector<char> &lines,int start, int end)
{

    if(start==end)
    {
        return;
    }

    else if(end==(start+2))
    {
        lines[(start+end)/2]=' ';
        return;
    }

    else 
    {
        int section_size=(end-start+1)/3;

        for(int i=start+section_size;i<start+2*section_size;i++)
        {
            lines[i]=' ';
        }

        separate(lines,start,start+section_size-1);
        separate(lines,start+2*section_size,start+3*section_size-1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    vector<int> inputs;

    while(!cin.eof())
    {
        cin>>N;
        inputs.push_back(N);

        //cin 상태 초기화
        cin.clear();
        //입력 버퍼 비움
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 버퍼를 비움

        //다음 문자가 enter key라면 입력 종료
        if (cin.peek() == '\n') 
        {
            break;
        }
    }

    /* 안됨
     while(cin>>N && N!='\n')
    {
        inputs.push_back(N);

        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 버퍼를 비움
   
        if (cin.peek() == '\n') 
        {
            break;
        }
    }
    */

    for(int i=0;i<inputs.size();i++)
    {
        int input=inputs[i];
        int length=pow(3,input);

        vector<char> lines(length,'-');

        int start=0;
        int end=lines.size()-1;

        separate(lines,start,end);

        for(auto e:lines)
        {
            cout<<e;
        }
        cout<<endl;
    }

    return 0;
}