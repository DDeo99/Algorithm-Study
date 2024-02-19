// BOJ 백준 2096번 내려가기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

short maxDp[3];
short minDp[3];
short minTemp[3];
short maxTemp[3];

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int num;
			cin >> num;
			
			if (i == 0)
			{
				maxDp[j] = num;
				minDp[j] = num;
			}

			else
			{
				if (j == 0)
				{
					int maxRes = max(maxDp[0], maxDp[1]) + num;
					maxTemp[0] = maxRes;

					int minRes = min(minDp[0], minDp[1]) + num;
					minTemp[0] = minRes;
				}
				else if (j == 1)
				{
					int maxRes = max(max(maxDp[0], maxDp[1]), maxDp[2]) + num;
					maxTemp[1] = maxRes;

					int minRes = min(min(minDp[0], minDp[1]), minDp[2]) + num;
					minTemp[1] = minRes;
				}

				else if (j == 2)
				{
					int maxRes = max(maxDp[1], maxDp[2]) + num;
					maxTemp[2] = maxRes;

					int minRes = min(minDp[1], minDp[2]) + num;
					minTemp[2] = minRes;
				}

			}
			maxDp[0] = maxTemp[0]; maxDp[1] = maxTemp[1]; maxDp[2] = maxTemp[2];
			minDp[0] = minTemp[0]; minDp[1] = minTemp[1]; minDp[2] = minTemp[2];
			}

		}
	

	cout << max(max(maxDp[0], maxDp[1]), maxDp[2]) << " " << min(min(minDp[0], minDp[1]), minDp[2]);
	
	return 0;
}