#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	const int INF = 10000;
	int n, s, d, i = 1, score = INF, cnt = 0;
	vector<vector<int>> dp(51, vector<int>(51, INF));
	vector<int> res(51, 0);

	cin >> n;

	for (int i = 1; i <= n; i++)
		dp[i][i] = 0;

	while (true)
	{
		cin >> s >> d;
		if (s == -1 && d == -1)
			break;

		dp[s][d] = 1;
		dp[d][s] = 1;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (res[i] < dp[i][j])
				res[i] = dp[i][j];
		}

		score = min(score, res[i]);
	}

	for (int i = 1; i <= n; i++)
		if (res[i] == score) cnt++;

	cout << score << " " << cnt << endl;

	for (int i = 1; i <= n; i++)
		if (res[i] == score)
			cout << i << " ";
}
