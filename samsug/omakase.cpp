// 삼성 코테 2023 하반기 오후 2번 오마카세
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

/**
 * 특정 고객을 기준으로 Hash로 풂
 * 초밥 다 먹은 상황을 새로운 명령어로 추가
 * 시간 순서대로 명령어들 나열 + 시간 같은 경우에는 cmd 순서로 나열
*/

int L,Q;
unordered_map<string,int> position; // 손님 앉은 자리
unordered_set<string> customerName; // 손님 이름
unordered_map<string,int> visitTime; // 손님 방문 시간
unordered_map<string,int> eatCnt; // 손님 먹을 초밥 개수

struct CMD{
    int cmd,x,t,n;
    string name;
};
vector<CMD> commands;
vector<CMD> sushiX;

long long s_num=0;
long long c_num=0;

bool comp(CMD left, CMD right)
{
    // 앞이 더 작도록
    if (left.t > right.t) return false;
    if (left.t < right.t) return true;

    if (left.cmd > right.cmd) return false;
    if (left.cmd < right.cmd) return true;

    return false;
}

void solution()
{
    for(int i=0;i<commands.size();i++)
    {
        if(commands[i].cmd!=100)
            continue;
        
        // 생성 초밥의 만든 시간, 초밥 위치, 손님 이름 정보
        CMD sushi = commands[i];

        int meetingTime=0;
        int eatingTime=0;

        // 손님 도착 전에 초밥 만듦
        if(sushi.t<visitTime[sushi.name])
        {  
            // 초밥 현재 위치
            int sushiPositon=sushi.x;

            // 방문 시간과 초밥 생성 시간 차이 -> 얼마나 회전 했는지
            int timeDiff=visitTime[sushi.name]-sushi.t;

            // 고객 방문 시점의 초밥 위치
            sushiPositon=(sushiPositon+timeDiff)%L;

            // 초밥보다 고객이 우측에 위치
            if(position[sushi.name]>=sushiPositon)
            {
                // 손님이 초밥 먹기 위해 기다리는 시간
                meetingTime=position[sushi.name]-sushiPositon;
            }

            // 초밥보다 고객이 좌측에 위치
            else
            {
                meetingTime=position[sushi.name]+L-sushiPositon;
            }

            // 초밥 먹은 시간
            eatingTime=visitTime[sushi.name]+meetingTime;
        }
        // 손님 도착 후에 초밥 만듦
        else
        {
            int sushiPositon=sushi.x;

            // 초밥보다 고객이 우측에 위치
            if(position[sushi.name]>=sushiPositon)
            {
                // 손님이 초밥 먹기 위해 기다리는 시간
                meetingTime=position[sushi.name]-sushiPositon;
            }

            // 초밥보다 고객이 좌측에 위치
            else
            {
                meetingTime=position[sushi.name]+L-sushiPositon;
            }

            // 초밥 먹은 시간
            eatingTime=sushi.t+meetingTime;
        }

        // 초밥 먹은 시간을 101로 저장
        CMD temp;
        temp.cmd=sushi.cmd+1;
        temp.t=eatingTime;
        temp.x=-1;
        temp.name=sushi.name;
        temp.n=-1;
        sushiX.push_back(temp);
    }

    // 기존 commands 벡터 뒤에 초밥 다먹은 정보 추가
    commands.insert(commands.end(),sushiX.begin(),sushiX.end());

    // t가 작은 것이 앞으로, cmd가 작을 수록 앞으로
    sort(commands.begin(),commands.end(),comp);

    for(int i=0;i<commands.size();i++)
    {
        if(commands[i].cmd==100)
            s_num++;
        else if(commands[i].cmd==101)
        {
            s_num--;
            string customer=commands[i].name;
            eatCnt[customer]--;
            if(eatCnt[customer]<=0)
                c_num--;
        }
        else if(commands[i].cmd==200)
        {
            c_num++;
        }
        else if(commands[i].cmd==300)
        {
            cout<<c_num<<" "<<s_num<<"\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>L>>Q;
  
    int time=1;

    for(int i=0;i<Q;i++)
    {
        int cmd=-1,t=-1,x=-1,n=-1;
        string name="";

        cin>>cmd;

        // 초밥 만들기
        if(cmd==100)
        {
            cin >> t >> x >> name;
        }

        // 손님 입장
        else if(cmd==200)
        {
            cin>>t>>x>>name>>n;

            customerName.insert(name);
            position[name]=x;
            visitTime[name]=t;
            eatCnt[name]=n;
        }

        // 사진 촬영
        else if(cmd==300)
            cin>>t;
        
        CMD temp;
        temp.cmd=cmd;
        temp.n=n;
        temp.name=name;
        temp.x=x;
        temp.t=t;
        commands.push_back(temp);
    }

    solution();

    return 0;
}