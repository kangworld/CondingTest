#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int visited[7];
vector<vector<int>> vec(7);

void BFS(int start)
{
	queue<int> q;

	q.push(start);
	visited[start] = true;

	while (q.size() > 0)
	{
		int now = q.front();
		q.pop();
		cout << now << " ";

		for (int next : vec[now])
		{
			if (visited[next])
				continue;

			q.push(next);
		}
	}
}

int main()
{
	freopen("input.txt", "rt", stdin);

	int s, e;

	for (int i = 1; i <= 6; i++)
	{
		cin >> s >> e;
		vec[s].push_back(e);
	}

	BFS(1);
}
