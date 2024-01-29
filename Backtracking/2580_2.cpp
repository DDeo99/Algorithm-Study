#include <iostream>
#include <vector>

using namespace std;

int length=9;
int matrix[9][9];
int level=0;
bool isComplete=false;

vector<pair<int,int>> idx;

bool flag(int x, int y)
{
    for(int i=0;i<length;i++)
    {
        if(i!=x && (matrix[i][y] == matrix[x][y]))
        {
            return false;
        }

        if(i!=y && (matrix[x][i] == matrix[x][y]))
        {
            return false;
        }
    }

    int xx=(x/3)*3;
    int yy=(y/3)*3;

    for(int i=xx;i<xx+3;i++)
    {
        for(int j=yy;j<yy+3;j++)
        {
            if((x!=i&&y!=j) & (matrix[x][y]==matrix[i][j]))
            {
                return false;
            }
        }
    }

    return true;
}

void sudoku(int cnt)
{
    if(cnt==level)
    {   
        isComplete=true;
        return;
    }

    int x = idx[cnt].first;
    int y = idx[cnt].second;

    for(int i=1;i<=9;i++)
    {
        matrix[x][y]=i;

        if(flag(x,y))
        {
            sudoku(cnt+1);
        }
        
        //없으면 스도쿠가 완성되어도 완성된 부분에 다시 루프를 타고 새로운 값 넣으려 함
        if(isComplete)
        {
            return;
        }
        
    }

    matrix[x][y]=0;
    return;

}

int main()
{

    for(int i=0;i<length;i++)
    {
        for(int j=0;j<length;j++)
        {
            int num;
            cin>>num;
            matrix[i][j]=num;

            if(num==0)
            {
                level++;
                idx.push_back({i,j});
            }
        }
    }

    cout<<endl;

    sudoku(0);

    for(int i=0;i<length;i++)
    {
        for(int j=0;j<length;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<'\n';
    }

    return 0;
}