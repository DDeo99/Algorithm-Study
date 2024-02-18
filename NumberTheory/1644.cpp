// BOJ 백준 1644번 소수의 연속합

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int cnt = 0;

vector<bool> isPrime;
vector<int> primeNums;

bool isP(int n)
{
    if(n==1)
    {
        return false;
    }

	for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }

    return true;
}

void result()
{
	int sum = 0;
    int s=0;
    int e=0;

	while (s<=e && e<primeNums.size())
	{
		if (sum < N)
		{
			sum += primeNums[e];
			e++;
		}

		else if (sum >= N)
		{
            if (sum == N)
            {
                cnt++;
            }

			sum -= primeNums[s];
			s++;
		}
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	cin >> N;

    if(N==1)
    {
        cout<< 0;
        return 0;
    }

    isPrime.resize(N+1,1);

    isPrime[0]=0;
    isPrime[1]=0;

    // 에라토스테네스의 체
    // 소수 판별은 제곱근까지만 보면 됨
	for (int i = 2; i<=sqrt(N); i++)
	{
        // 소수가 아님으로 판정된 수면 continue
		if(!isPrime[i])
        {
            continue;
        }
        // 현재 값만큼 뛰면서 체크
        for(int j=i+i;j<=N;j+=i)
        {
            isPrime[j]=false;
        }
        
	}

    for(int i=2;i<=N;i++)
    {
        if(isPrime[i])
        {
            primeNums.push_back(i);
        }
    }

	result();

    if(isP(N))
    {
        cnt++;
    }

	cout << cnt;

	return 0;
}



