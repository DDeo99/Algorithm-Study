// BOJ 백준 2096번 내려가기
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N;

 vector<int> maxDP(3,0), minDP(3,0);
 vector<int> nextMaxDP(3), nextMinDP(3);

int main()
{
	cin >> N;
	
	for(int i=0;i<N;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;

		// DP[0]은 0번 인덱스에 올 수 있는 가장 큰 값 or 가장 작은 값
		// 그림에 현혹 X
		
		nextMaxDP[0]=max(maxDP[0],maxDP[1])+a;
		nextMaxDP[1]=max(max(maxDP[0],maxDP[1]),maxDP[2])+b;
		nextMaxDP[2]=max(maxDP[1],maxDP[2])+c;
		maxDP=nextMaxDP;

		nextMinDP[0]=min(minDP[0],minDP[1])+a;
		nextMinDP[1]=min(min(minDP[0],minDP[1]),minDP[2])+b;
		nextMinDP[2]=min(minDP[1],minDP[2])+c;
		minDP=nextMinDP;
	}

	sort(maxDP.begin(),maxDP.end());
	sort(minDP.begin(),minDP.end());

	cout<<maxDP[2]<<" "<<minDP[0];

	return 0;
}