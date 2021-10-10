#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	int dp[101][1001], t[101], s[101];

	cin >> n >> m;

	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= n; i++)
		cin >> s[i] >> t[i];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (j - t[i] >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - t[i]] + s[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[n][m];
}
