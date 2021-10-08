#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int dp[501];
	int v[13];
	int n, m;

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> v[i];

	cin >> m;

	fill(dp, dp + m + 1, 501);
	dp[0] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = v[i]; j <= m; j++)
			dp[j] = min(dp[j], dp[j - v[i]] + 1);

	cout << dp[m];
}
