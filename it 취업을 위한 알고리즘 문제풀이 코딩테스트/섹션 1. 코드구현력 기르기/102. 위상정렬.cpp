#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	freopen("input.txt", "rt", stdin);
	
	int n, m, s, d;
	cin >> n >> m;
	queue<int> q;
	vector<int> degree(n + 1, 0);
	vector<vector<int>> gp(n+1, vector<int>());

	for (int i = 1; i <= m; i++)
	{
		cin >> s >> d;
		degree[d]++;
		gp[s].push_back(d);
	}

	for (int i = 1; i <= n; i++)
		if (degree[i] == 0)
			q.push(i);
		
	while (!q.empty())
	{
		int now = q.front();
		cout << now << " ";
		q.pop();

		for (int i = 0; i < gp[now].size(); i++)
		{
			int next = gp[now][i];

			degree[next]--;

			if (degree[next] == 0)
				q.push(next);
		}
	}
}
