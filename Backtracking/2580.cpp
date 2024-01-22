// BOJ 백준 2580번 스도쿠

#include <iostream>
#include <vector>

using namespace std;

bool isComplete = false;

bool isOkay(vector<vector<int>> &matrix, int x, int y)
{
    for(int i=0;i<9;i++)
    {
        if((i!=x) && (matrix[x][y]==matrix[i][y])) // 같은 행에 같은 값 있으면
        {
            return false;
        }

        if((i!=y) && (matrix[x][y]==matrix[x][i])) // 같은 열에 같은 값 있으면
        {
            return false;
        }
    }

    // 3x3 사각형 구역에서 같은 값 있으면
    int s_x=x/3;
    int s_y=y/3;

    for(int i=3*s_x;i<3*s_x+3;i++)
    {
        for(int j=3*s_y;j<3*s_y+3;j++)
        {
            if(((x!=i) && (y!=j)) && (matrix[x][y]==matrix[i][j]))
            {
                return false;
            }
        }
    }

    return true;

}

void sudoku(vector<vector<int>> &matrix,vector<pair<int,int>> &blank, int level, int cnt)
{
    if(cnt==level)
    {
        isComplete=true;
        return;
    }

    for(int i=1;i<=9;i++)
    {
        matrix[blank[cnt].first][blank[cnt].second]=i;
        if(isOkay(matrix,blank[cnt].first,blank[cnt].second))
        {
            sudoku(matrix,blank,level,cnt+1);
        }
        if(isComplete)
        {
            return;
        }
    }
    matrix[blank[cnt].first][blank[cnt].second]=0;
    return;
}
/*
void sudoku(vector<vector<int>> &matrix, int y, int level)
{
    //한 줄씩 넘어가면서 체크 + 작은 사각형 체크
    if(y==level)
    {
        return;
    }

    for(int i=0;i<9;i++)
    {
        if(matrix[i][y]==0)
        {
            for(int j=1;j<10;j++)
            {
                matrix[i][y]=j;
                if(isOkay(matrix,i,y))
                {
                    sudoku(matrix,y+1,level);
                    break;
                }
            }
        }
    }

}
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<vector<int>> matrix(9,vector<int>(9,0));
    vector<pair<int,int>> blank;

    pair<int,int> p;

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin>>matrix[i][j];
            if(matrix[i][j]==0)
            {
                p.first=i;
                p.second=j;
                blank.push_back(p);
            }
        }
    }

    sudoku(matrix,blank,blank.size(),0);

    for(auto &e : matrix)
    {
        for(int value : e)
        {
            cout<< value << " ";
        }
        cout<<'\n';
    }

    return 0;
}