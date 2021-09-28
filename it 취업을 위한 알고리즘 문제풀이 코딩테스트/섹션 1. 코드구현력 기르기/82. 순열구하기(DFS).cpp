#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, r, total = 0;
int arr[16];
int res[16];
bool visited[16];

void DFS(int level)
{
	if (level == r + 1)
	{
		total += 1;

		for (int i = 1; i < level; i++)
			cout << res[i] << " ";
		cout << endl;

		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (visited[i])
			continue;

		visited[i] = true;
		res[level] = arr[i];
		DFS(level + 1);
		visited[i] = false;
	}
}

int main(void)
{
	cin >> n >> r;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	DFS(1);

	cout << total;
}