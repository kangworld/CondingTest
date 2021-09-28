#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, t, p, res = 0;
pair<int, int> arr[16];

void DFS(int now, int sum)
{
	if (now == n + 1)
	{
		if (sum > res)
			res = sum;

		return;
	}

	int next = now + arr[now].first;

	if(next <= n + 1)
		DFS(next, sum + arr[now].second);
	
	DFS(now + 1, sum);
}

int main(void)
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> t >> p;

		arr[i] = make_pair(t, p);
	}

	DFS(1, 0);

	cout << res;
}