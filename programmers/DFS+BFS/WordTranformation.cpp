#include <string>
#include <vector>
#include <map>
#include <limits>

using namespace std;
int ans = numeric_limits<int>::max(); // 충분히 큰 값으로 초기화

void dfs(string begin, string target, vector<string> &words, vector<bool> &visited, int cnt)
{
    if (begin == target)
    {
        ans = min(ans, cnt);
        return;
    }

    for (int i = 0; i < words.size(); i++)
    {
        if (!visited[i])
        {
            int diff = 0;
            for (int j = 0; j < begin.size(); j++)
            {
                if (begin[j] != words[i][j])
                    diff++;
            }

            if (diff == 1)
            {
                visited[i] = true;
                dfs(words[i], target, words, visited, cnt + 1);
                visited[i] = false;
            }
        }
    }
}

int solution(string begin, string target, vector<string> words)
{
    int answer = 0;

    vector<bool> visited(words.size(), false);
    
    dfs(begin, target, words, visited, 0);

    if (ans == numeric_limits<int>::max()) // 변환할 수 없는 경우
        return 0;
    else
        answer = ans;

    return answer;
}