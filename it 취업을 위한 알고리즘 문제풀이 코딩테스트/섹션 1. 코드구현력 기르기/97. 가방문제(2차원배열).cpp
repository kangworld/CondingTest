#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, t;
int w[31], v[31];
int dp[31][1001];

int main(void)
{
	cin >> n >> t;

	for (int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= t; j++)
		{
			if (j - w[i] >= 0)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - w[i]] + v[i]);
			}
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[n][t];

	return 0;
}