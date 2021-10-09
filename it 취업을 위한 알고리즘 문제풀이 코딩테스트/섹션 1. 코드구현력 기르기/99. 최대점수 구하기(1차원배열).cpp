#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	int dp[1001], t[101], s[101];

	cin >> n >> m;

	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= n; i++)
		cin >> s[i] >> t[i];

	for (int i = 1; i <= n; i++)
	{
		for (int j = m; j >= t[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - t[i]] + s[i]);
		}
	}

	cout << dp[m];
}
