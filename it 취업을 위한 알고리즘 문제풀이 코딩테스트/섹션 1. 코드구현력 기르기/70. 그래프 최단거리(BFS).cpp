#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int visited[21];
int dist[21];
vector<int> vec[21];
int n, m, nd1, nd2;
queue<int> q;


void BFS(int start)
{
	visited[start] = true;
	dist[start] = 0;
	q.push(start);

	while (q.size() > 0)
	{
		int now = q.front();
		q.pop();

		for (int next : vec[now])
		{
			if (visited[next])
				continue;

			visited[next] = true;
			q.push(next);

			dist[next] = dist[now] + 1;
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		cin >> nd1 >> nd2;
		vec[nd1].push_back(nd2);
	}

	BFS(1);

	for (int i = 2; i <= n; i++)
		cout << i << " : " << dist[i] << endl;
}
