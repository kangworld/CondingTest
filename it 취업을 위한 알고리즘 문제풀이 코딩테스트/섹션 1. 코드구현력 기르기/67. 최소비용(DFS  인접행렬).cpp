#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, nd1, nd2, cost, res = 99999;
int arr[21][21];
bool visited[21];

void DFS(int now, int sum)
{
	if (now == n)
	{
		res = sum < res ? sum : res;
		return;
	}

	for (int next = 1; next <= n; next++)
	{
		if (!arr[now][next])
			continue;

		if (visited[next])
			continue;

		visited[next] = true;
		DFS(next, sum + arr[now][next]);
		visited[next] = false;
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		cin >> nd1 >> nd2 >> cost;
		arr[nd1][nd2] = cost;
	}

	visited[1] = true;
	DFS(1, 0);

	cout << res;
}