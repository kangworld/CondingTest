#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[11];
int n, m, res = 0;

void DFS(int level, int sum)
{
	if (level == n + 1)
	{
		if (sum == m) res++;
		return;
	}

	DFS(level + 1, sum + a[level]);
	DFS(level + 1, sum - a[level]);
	DFS(level + 1, sum);
}

int main()
{

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	DFS(1, 0);

	if (res == 0)
		cout << "-1";
	else
		cout << res;
}