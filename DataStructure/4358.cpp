//BOJ 백준 4358번 생태학

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>

using namespace std;

map<string,double> trees;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    double total=0.0;
    string tree;
    while(getline(cin,tree))
    {
        if(trees.count(tree)==0)
        {
            trees[tree]=1;
            total+=1;
        }

        else
        {
            trees[tree]++;
            total+=1;
        }
    }

    for(auto iter=trees.begin();iter!=trees.end();iter++)
    {
        iter->second=iter->second/total*100;
    }

    for(auto iter=trees.begin();iter!=trees.end();iter++)
    {
        cout<<fixed;
        cout.precision(4);
        cout<<iter->first<<" "<<iter->second<<"\n";
    }
    return 0;
}