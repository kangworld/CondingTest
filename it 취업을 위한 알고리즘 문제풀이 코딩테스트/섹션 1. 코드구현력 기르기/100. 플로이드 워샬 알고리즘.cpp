#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	const int INF = 100000;
	int n, m, s, d, c;
	vector<vector<int>> dist(201, vector<int>(201, INF));

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		dist[i][i] = 0;

	for (int i = 1; i <= m; i++)
	{
		cin >> s >> d >> c;

		dist[s][d] = c;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dist[i][j] == INF)
				cout << "M ";
			else
				cout << dist[i][j] << " ";
		}
		cout << endl;
	}
}
