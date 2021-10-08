#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int map[21][21];
int dp[21][21];

int main()
{
	cin >> n;

	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= n; x++)
			cin >> map[y][x];

	for (int pos = 1; pos <= n; pos++)
	{
		dp[1][pos] = dp[1][pos - 1] + map[1][pos];
		dp[pos][1] = dp[pos - 1][1] + map[pos][1];
	}

	for (int y = 2; y <= n; y++)
	{
		for (int x = 2; x <= n; x++)
		{
			dp[y][x] = min(dp[y - 1][x], dp[y][x - 1]) + map[y][x];
		}
	}

	cout << dp[n][n];
}
