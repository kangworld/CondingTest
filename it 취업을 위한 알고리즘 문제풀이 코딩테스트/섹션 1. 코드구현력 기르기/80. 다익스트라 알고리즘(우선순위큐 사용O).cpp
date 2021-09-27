#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct node
{
	int pos;
	int cost;

	node(int _pos, int _cost)
	{
		pos = _pos;
		cost = _cost;
	}

	bool operator<(const node& a) const
	{
		return cost > a.cost;
	}
};

int main(void)
{
	int n, m, k, start, dest, cost;
	int dist[21];
	vector<pair<int, int>> gp[21];
	priority_queue<node> prq;

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
		dist[i] = INT32_MAX;

	for (int i = 0; i < m; i++)
	{
		cin >> start >> dest >> cost;

		gp[start].push_back(make_pair(dest, cost));
	}

#pragma region Dijkstra
	dist[k] = 0;
	prq.push(node(k, 0));

	while (!prq.empty())
	{
		node now = prq.top();
		prq.pop();

		if (dist[now.pos] < now.cost)
			continue;

		for (pair<int, int> next : gp[now.pos])
		{
			int nextDist = dist[now.pos] + next.second;

			if (nextDist < dist[next.first])
			{
				dist[next.first] = nextDist;
				prq.push(node(next.first, nextDist));
			}
		}
	}
#pragma endregion

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