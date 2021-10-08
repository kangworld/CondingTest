#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int map[21][21];
int dp[21][21];

int DP(int y, int x)
{
	if (dp[y][x])
		return dp[y][x];

	if (y == 1 && x == 1)
		return map[y][x];
	else if (y == 1)
		return dp[y][x] = DP(y, x - 1) + map[y][x];
	else if (x == 1)
		return dp[y][x] = DP(y - 1, x) + map[y][x];

	return dp[y][x] = min(DP(y - 1, x), DP(y, x - 1)) + map[y][x];
}

int main()
{
	cin >> n;

	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= n; x++)
			cin >> map[y][x];

	cout << DP(n, n);
}
