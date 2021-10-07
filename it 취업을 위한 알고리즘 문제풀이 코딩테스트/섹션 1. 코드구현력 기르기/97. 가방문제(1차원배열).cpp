#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, t;
int w[31], v[31];
int dp[1001];

int main(void)
{
	cin >> n >> t;

	for (int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];

	for (int i = 1; i <= n; i++)
	{
		for (int j = w[i]; j <= t; j++)
		{
			if (j - w[i] >= 0)
				dp[j] = max(dp[j - w[i]] + v[i], dp[j]);
		}
	}

	cout << dp[t];
	return 0;
}