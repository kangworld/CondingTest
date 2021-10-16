#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, f1, f2, start, dest;
vector<int> vec[1001];
vector<bool> visited(1001, false);
vector<int> path(1001, 0);

void BFS()
{
	queue<int> q;

	q.push(start);
	visited[start] = true;
	path[start] = start;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int next : vec[now])
		{
			if (visited[next])
				continue;

			q.push(next);
			visited[next] = true;
			path[next] = now;
		}
	}
}

bool CalculatePath()
{
	int now = dest;

	while (now != path[now])
	{
		now = path[now];
		if (now == start)
			return true;
	}

	return now == dest ? true : false;
}

int main(void)
{
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		cin >> f1 >> f2;

		vec[f1].push_back(f2);
		vec[f2].push_back(f1);
	}
	
	cin >> start >> dest;

	BFS();

	if (CalculatePath())
		cout << "YES";
	else
		cout << "NO";
}
