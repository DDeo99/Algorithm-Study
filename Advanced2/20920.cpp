// BOJ 20920번 영단어 암기는 괴로워

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

int main()
{

    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N, M;

    cin>>N>>M;

    vector<string> words;
    map<string, int> frequency;

    for(int i=0;i<N;i++)
    {
        string word;
        cin>>word;
        if(!(word.length()<M))
        {
            words.push_back(word);
        }
    }
    
    for(string e : words)
    {
        frequency[e]++;
    }

    vector<pair<string,int>> ordered_words(frequency.begin(), frequency.end());

    sort(ordered_words.begin(), ordered_words.end(), [](const auto &left, const auto &right)
    {

        if(left.second == right.second)
        {
            if(left.first.length() == right.first.length())
            {
                return left.first < right.first;
            }

            else
            {
                return left.first.length() > right.first.length();
            }
        }

        else
        {
            return left.second > right.second;
        }
    });

    for(auto s : ordered_words)
    {
        cout << s.first << '\n';
    }

/*
    이렇게하면 시간초과 난다.
    for(int i=0;i<ordered_words.size();i++)
    {
       cout<<ordered_words[i].first<<endl;
    }
*/
    return 0;
}
