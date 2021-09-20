#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, e1, e2, res = 0;
vector<int> vec[21];
bool visited[21];

void DFS(int now)
{
	if (now == n)
	{
		res++;
		return;
	}

	for (int next : vec[now])
	{
		if (visited[next])
			continue;

		visited[next] = true;
		DFS(next);
		visited[next] = false;
	}
}

int main()
{
	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		cin >> e1 >> e2;

		vec[e1].push_back(e2);
	}

	visited[1] = true;
	DFS(1);

	cout << res;
}