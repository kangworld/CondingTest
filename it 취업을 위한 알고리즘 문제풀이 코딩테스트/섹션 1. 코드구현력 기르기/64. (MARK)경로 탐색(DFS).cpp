#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, e1, e2, res = 0;
bool visited[21];
int arr[21][21];

void DFS(int now)
{
	if (now == n)
	{
		res++;
		return;
	}

	for (int next = 1; next <= n; next++)
	{
		if (visited[next])
			continue;

		if (arr[now][next] != 1)
			continue;

		visited[next] = true;
		DFS(next);
		visited[next] = false;
	}
	
}

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		cin >> e1 >> e2;
		arr[e1][e2] = 1;
	}

	visited[1] = true;
	DFS(1);

	cout << res;
}