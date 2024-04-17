#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    int answer = 0;
    
    if(N==number)
        return 1;
    
    vector<unordered_set<int> > s(8);
    
    int KN=0;
    for(int i=0;i<8;i++)
    {
        KN=KN*10+N; // K개의 N (NNNN...)
        s[i].insert(KN);
        
        for(int j=0;j<i;j++)
        {
            for(int k=0;k<i;k++)
            {
                // i번째는 j번째 + k번째 + NNNN 의 합
                if(i!=j+k+1)
                    continue;
                for(auto a:s[j])
                {
                    for(auto b:s[k])
                    {
                        s[i].insert(a+b);
                        s[i].insert(a*b);
                        if(a-b>0) s[i].insert(a-b);
                        if(a/b>0) s[i].insert(a/b);
                    }
                }
                
            }
        }
            
        if(s[i].find(number)!=s[i].end())
            return i+1;
    }
    
    return -1;
}