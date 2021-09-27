#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, k;
bool visited[21] = { false };
int dist[21] = { INT32_MAX };
vector<pair<int, int>> gp[21];

void Dijkstra()
{
	dist[k] = 0;

	while (true)
	{
		int closest = INT32_MAX;
		int now = -1;

		for (int i = 1; i <= n; i++)
		{
			if (visited[i])
				continue;

			if (dist[i] == INT32_MAX)
				continue;

			if (dist[i] < closest)
			{
				now = i;
				closest = dist[i];
			}
		}

		if (now == -1)
			break;

		visited[now] = true;

		for (pair<int, int> next : gp[now])
		{
			if (visited[next.first])
				continue;

			int nextDist = dist[now] + next.second;

			if (nextDist < dist[next.first])
				dist[next.first] = nextDist;
		}
	}
}

void ShowDist()
{
	for (int i = 1; i <= n; i++)
	{
		if (i == k)
			continue;

		if (dist[i] == INT32_MAX)
			cout << i << " : impossible" << endl;
		else
			cout << i << " : " << dist[i] << endl;
	}
}

int main(void)
{
	int start, dest, cost;

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
		dist[i] = INT32_MAX;

	for (int i = 0; i < m; i++)
	{
		cin >> start >> dest >> cost;

		gp[start].push_back(make_pair(dest, cost));
	}

	Dijkstra();

	ShowDist();
}