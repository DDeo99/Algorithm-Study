// BOJ 백준 1753번 최단경로

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int>> route[300001];
long long costMax = 11111111;
vector<long long> dist;
vector<bool> visited;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int V, E;
	cin >> V >> E;
	int K;
	cin >> K;
	for (int i = 0; i < E; i++)
	{
		//시작, 끝, 가중치
		int u, v, w;

		cin >> u >> v >> w;
		route[u].push_back({ w,v });
	}
	dist.resize(V + 1, costMax);
	visited.resize(V + 1, 0);

	dist[K] = 0;

	q.push({ 0, K });

	while(!q.empty())
	{
		pair<int, int> current = q.top();
		int cIdx = current.second;
		int cCost = current.first;
		q.pop();

        if (visited[cIdx])
        {
            continue;
        }
        visited[cIdx] = 1;


        //if(dist[cIdx]!=cCost)
        //    continue;

		for (int i = 0; i < route[cIdx].size(); i++)
		{
			pair<int, int> next = route[cIdx][i];
			int nIdx = next.second;
			int nCost = next.first;

			if (dist[nIdx] > cCost + nCost)
			{
				dist[nIdx] = cCost + nCost;
				q.push({dist[nIdx],nIdx});
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == costMax)
		{
			cout << "INF" << "\n";
		}
		else
			cout << dist[i] << "\n";
	}

	return 0;
}