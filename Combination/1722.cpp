// BOJ 백준 1722번 순열의 순서

#include <iostream>
#include <vector>

using namespace std;

int N;
int T;
long long k;
vector<int> nums;

vector<int> newNums;
vector<long long> F;

int main()
{
	cin >> N;

	cin >> T;

	F.resize(N+1);
	F[0] = 1;
	for (int i = 1; i <= N; i++)
	{
		F[i] = F[i - 1] * i;
	}

	if (T==1)
	{
        vector<bool> flag;
        flag.resize(N+1, 0);
        newNums.resize(N+1);

		cin >> k;

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (flag[j] == 0)
				{
					if(k<=F[N-i])
					{
						newNums[i] = j;
						flag[j] = 1;
						break;
					}
					else
					{
						k -= F[N - i];
					}
					
				}
			}
		}
		
		for (int i = 1; i <= N; i++)
		{
			cout << newNums[i] << " ";
		}

	}
	
	else if(T==2)
	{
        // 맨 앞자리가 1 -> a
        // 맨 앞자리가 2 -> 3! + a
        // 맨 앞자리가 3 -> 3! + 3! + a

        vector<bool> flag;
        flag.resize(N+1, 0);
        nums.resize(N+1);

		for (int i = 1; i <= N; i++)
		{
			int num;
			cin >> num;
			nums[i]=num;
		}

        long long cnt=0;

        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<nums[i];j++)
            {
                if(flag[j]==0)
                {
                    cnt+=F[N-i];
                }
            }
            flag[nums[i]]=1;
        }

        cout<<cnt+1;
	}
	
	return 0;
}