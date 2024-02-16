// BOJ 백준 2042번 구간 합 구하기

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long N, M, K;
vector<long long> nums;
vector<long long> idxTree;

int main()
{
	cin >> N >> M >> K;

	int n = 0;
	while (N >= (long long)pow(2, n))
	{
		n++;
	}

	long long newSize = (long long)pow(2, n);
	nums.resize(newSize);

	for (long long i = newSize - N; i < newSize; i++)
	{
		long long num;
		cin >> num;
		nums[i] = num;
	}

	long long size = newSize * 2;

	idxTree.resize(size, 0);

	for (long long i = newSize; i < size; i++)
	{
		idxTree[i] = nums[i - newSize];
	}

	for (long long i = newSize - 1; i > 0; i--)
	{
		idxTree[i] = idxTree[i * 2] + idxTree[i * 2 + 1];
	}

	for (int i = 0; i < M + K; i++)
	{
		long long a, b, c;
		cin >> a >> b >> c;
		long long newB = size - N - 1 + b;
		long long newC = size - N - 1 + c;
		if (a == 1)
		{
			idxTree[newB] = c;
			while (newB > 1)
			{
				if (newB % 2 == 0)
				{
					idxTree[newB / 2] = idxTree[newB] + idxTree[newB + 1];
				}
				else
				{
					idxTree[newB / 2] = idxTree[newB] + idxTree[newB - 1];
				}
				newB /= 2;
			}
		}

		else if (a == 2)
		{
			long long sum = 0;
			long long start = newB;
			long long end = newC;
		
			while (start <= end)
			{
				if (start % 2 == 1)
				{
					sum = sum + idxTree[start];
					start++;
				}

				if (end % 2 == 0)
				{
					sum = sum + idxTree[end];
					end--;
				}

				start = start / 2;
				end = end / 2;
			}
			cout << sum << "\n";
		}
	}

	return 0;
}