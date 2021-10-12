#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Edge
{
	int start;
	int dest;
	int cost;

	Edge(int _start, int _dest, int _cost)
	{
		start = _start;
		dest = _dest;
		cost = _cost;
	}
};

int main()
{
	int n, m, startCity, destCity, s, d, c;
	vector<Edge> edge;
	vector<int> dist(101, INT32_MAX);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> s >> d >> c;
		edge.push_back(Edge(s, d, c));
	}

	cin >> startCity >> destCity;

	dist[startCity] = 0;

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			s = edge[j].start;
			d = edge[j].dest;
			c = edge[j].cost;

			if (dist[s] == INT32_MAX)
				continue;

			if (dist[s] + c < dist[d])
				dist[d] = dist[s] + c;
		}
	}

	for (int j = 0; j < m; j++)
	{
		s = edge[j].start;
		d = edge[j].dest;
		c = edge[j].cost;

		if (dist[s] == INT32_MAX)
			continue;

		if (dist[s] + c < dist[d])
		{
			cout << "-1";
			return 0;
		}
	}

	cout << dist[destCity];
	return 0;
}
