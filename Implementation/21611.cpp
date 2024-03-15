// BOJ 백준 21611번 마법사 상어와 블리자드
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
/*
int N,M;
pair<int,int> shark;
vector<vector<int>> matrix;
vector<int> temp;

int bx[]={0,0,0,-1,1};
int by[]={0,-1,1,0,0};
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void blizard(int d, int s);
void makeArr(int x, int y);
void makeMatrix(int x, int y);
void moveMarble();
int bomb();
void changeMarble();

int ans=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N>>M;
    matrix.resize(N+1,vector<int>(N+1));

    // 구슬 입력
    for(int i=1;i<N+1;i++)
    {
        for(int j=1;j<N+1;j++)
        {
            int num;
            cin>>num;
            matrix[j][i]=num;
        }
    }

    // 상어 위치
    shark={(N+1)/2,(N+1)/2};

    for(int i=0;i<M;i++)
    {  
        //d방향으로 s거리만큼 폭파
        // 위:1 아래:2 왼쪽:3 오른쪽:4
        int d,s;
        cin>>d>>s;
 
        blizard(d,s);
        moveMarble();
        ans+=bomb();
        changeMarble();
    }

    cout<<ans;   
    
    return 0;
}

void makeArr(int x, int y)
{
   return;
}

void makeMatrix(int x, int y)
{
    return;
}

void blizard(int d, int s)
{
    int x=shark.first;
    int y=shark.second;

    for(int i=0;i<s;i++)
    {
        y+=by[d];
        x+=bx[d];
        matrix[x][y]=0;
    }
}

void moveMarble()
{
    queue<int> q;
    int x=shark.first;
    int y=shark.second;
    int cnt=0;

    for(int d=0;x!=0;d++)
    {
        // 좌,하  우,상 으로 같은 횟수만큼 두번씩
        d%=4;
        if(d%2==0)
            cnt++;
        for(int i=0;i<cnt;i++)
        {
            y+=dy[d];
            x+=dx[d];
            if(matrix[x][y])
            {
                q.push(matrix[x][y]);
                matrix[x][y]=0;
            }
        }
    }

    x=shark.first;
    y=shark.second;
    cnt=0;
    // q에서 다시 matrix로
    for(int d=0;x!=0;d++)
    {
        d%=4;
        if(d%2==0)
            cnt++;
        for(int i=0;i<cnt;i++)
        {
            y+=dy[d];
            x+=dx[d];
            if(q.empty())
            {
                x=0; // 바깥 루프 종료 위함함
                break;
            }
            else
            {
                matrix[x][y]=q.front();
                q.pop();
            }
        }
    }
}


// 1x(1번 개수) + 2x(2번 개수) + 3x(3번 개수)
int bomb()
{
    int res=0;
    while(true)
    {
        // 폭발하는 구슬 없을 때까지 
        bool isEnd=true;
        int x=shark.first;
        int y=shark.second;
        int cnt=0;

        int before=0;
        vector<pair<int,int>> temp;

        for(int d=0;x!=0;d++)
        {
            d%=4;
            if(d%2==0)
                cnt++;
            for(int i=0;i<cnt;i++)
            {
                x+=dx[d];
                y+=dy[d];
                if(matrix[x][y]==before)
                    temp.push_back({x,y}); // 이전 구슬과 같으면 저장
                else
                {
                    if(temp.size()<4)
                    {
                        temp.clear();
                        before=matrix[x][y];
                        temp.push_back({x,y});
                    }

                    else
                    {
                        //폭파
                        isEnd=false;
                        res+=before*temp.size();
                        for(int i=0;i<temp.size();i++)
                        {
                            matrix[temp[i].first][temp[i].second]=0;
                        }
                        temp.clear();
                        before=matrix[x][y];
                        temp.push_back({x,y});
                    }
                }
            }
        }
        if(isEnd)
            return res;
        else
            moveMarble();
    }
}

void changeMarble()
{
    queue<int> q;

    int x=shark.first;
    int y=shark.second;
    int cnt=0;
    int A=0,B=0;

    for(int d=0;x!=0;d++)
    {
        d%=4;
        if(d%2==0)
            cnt++;
        for(int i=0;i<cnt;i++)
        {
            x+=dx[d];
            y+=dy[d];

            if(matrix[x][y]==B)
                A++;

            //그룹 바뀜
            else
            {
                if(B!=0)
                {
                    q.push(A);
                    q.push(B);
                }
                B=matrix[x][y];
                A=1;
            }
        }
    }

    x=shark.first;
    y=shark.second;
    cnt=0;

    for(int d=0;x!=0;d++)
    {
        d%=4;
        if(d%2==0)
            cnt++;
        for(int i=0;i<cnt;i++)
        {
            x+=dx[d];
            y+=dy[d];
            if(x==0)
                break;

            if(q.empty())
                matrix[x][y]=0;
            else
            {
                matrix[x][y]=q.front();
                q.pop();
            }
        }
    }
}
*/

int N,M;

vector<vector<int>> matrix;
pair<int,int> shark;

// 1:상 2:하 3:좌 4:우
int bx[]={0,0,0,-1,1};
int by[]={0,-1,1,0,0};

// 좌 하 우 상
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void blizard(int d, int s)
{
    int x=shark.first;
    int y=shark.second;
    for(int i=0;i<s;i++)
    {
        x+=bx[d];
        y+=by[d];
        matrix[x][y]=0;
    }
}

void moveMarble()
{
    queue<int> q;

    int x=shark.first;
    int y=shark.second;
    // 좌 하 , 우 상 반복   
    int cnt=0;

    for(int d=0;x!=0;d++)
    {
        d%=4;
        if(d%2==0)
            cnt++;
        for(int i=0;i<cnt;i++)
        {
            x+=dx[d];
            y+=dy[d];

            if(x==0)
                break;

            if(matrix[x][y])
            {
                q.push(matrix[x][y]);
                matrix[x][y]=0; // 안해주면 틀림
            }
        }
    }

    x=shark.first;
    y=shark.second;
    cnt=0;

    for(int d=0;x!=0;d++)
    {
        d%=4;
        if(d%2==0)
            cnt++;
        for(int i=0;i<cnt;i++)
        {
            x+=dx[d];
            y+=dy[d];

            if(q.empty())
            {
                x=0;
                break;
            }
            else
            {
                matrix[x][y]=q.front();
                q.pop();
            }
        }
    }
}

void moveMarble2()
{
    vector<int> arr;

    int x=shark.first;
    int y=shark.second;
    int cnt=0;

    for(int d=0;x!=0;d++)
    {
        d%=4;
        if(d&2==0)
            cnt;;
        for(int i=0;i<cnt;i++)
        {
            x+=dx[d];
            y+=dy[d];

            if(x==0)
                break;

            if(matrix[x][y])
            {
                arr.push_back(matrix[x][y]);
                matrix[x][y]=0;
            }
        }
    }

    x=shark.first;
    y=shark.second;
    cnt=0;

    reverse(arr.begin(),arr.end());

    for(int d=0;x!=0;d++)
    {
        d%=4;
        if(d%2==0)
            cnt++;
        for(int i=0;i<cnt;i++)
        {
            x+=dx[d];
            y+=dy[d];

            if(x==0)
                break;

            if(arr.size()==0)
            {
                x=0;
                break;
            }
            else
            {
                matrix[x][y]=arr.back();
                arr.pop_back();
            }
        }
    }
}

int bomb()
{
    int res=0;
    while(1)
    {
        int x=shark.first;
        int y=shark.second;
        int cnt=0;
        int before=0;
        vector<pair<int,int>> temp;
        bool isEnd=true;

        for(int d=0;x!=0;d++)
        {
            d%=4;
            if(d%2==0)
                cnt++;
            for(int i=0;i<cnt;i++)
            {
                x+=dx[d];
                y+=dy[d];

                if(x==0 || y==0)
                    break;

                if(matrix[x][y]==before)
                {
                    temp.push_back({x,y});
                }
                else
                {
                    if(temp.size()<4)
                    {
                        temp.clear();
                        before=matrix[x][y];
                        temp.push_back({x,y});
                    }
                    else
                    {
                        isEnd=false;
                        res+=before*temp.size();
                        for(int i=0;i<temp.size();i++)
                        {
                            matrix[temp[i].first][temp[i].second]=0;
                        }
                        temp.clear();
                        before=matrix[x][y];
                        temp.push_back({x,y});
                    }
                }
            }
        }
        if(isEnd)
            return res;
        else
            moveMarble();
    }
}

void changeMarble()
{
    queue<int> q;

    int x=shark.first;
    int y=shark.second;
    int cnt=0;
    //A는 그룹 구슬 개수, B는 구슬 번호
    int A=0,B=-1;

    for(int d=0;x!=0;d++)
    {
        d%=4;
        if(d%2==0)
            cnt++;
        for(int i=0;i<cnt;i++)
        {
            x+=dx[d];
            y+=dy[d];

            if(x==0)
                break;

            if(matrix[x][y]==B)
                A++;
            else
            {

                q.push(A);
                q.push(B);
                B=matrix[x][y];
                A=1;
            }
        }
    }

    x=shark.first;
    y=shark.second;
    cnt=0;

    for(int d=0;x!=0;d++)
    {
        d%=4;
        if(d%2==0)
            cnt++;
        for(int i=0;i<cnt;i++)
        {
            x+=dx[d];
            y+=dy[d];

            if(x==0)
                break;

            if(q.empty())
            {
                x=0;
                break;
            }

            else
            {
                matrix[x][y]=q.front();
                q.pop();
            }
        }
    }
}

int ans=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N>>M;
    matrix.resize(N+1,vector<int>(N+1));

    // 초기 구슬 정보
    for(int i=1;i<N+1;i++)
    {
        for(int j=1;j<N+1;j++)
        {
            cin>>matrix[j][i];
        }
    }

    shark={(N+1)/2,(N+1)/2};

    for(int i=0;i<M;i++)
    {
        int d,s;
        cin>>d>>s;

        blizard(d,s);
        moveMarble();
        ans+=bomb();
        changeMarble();
    }

    cout<<ans;

    return 0;
}
