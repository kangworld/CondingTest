#include <iostream>

using namespace std;

int main()
{
	int arr[101], dp[101];
	int n, len, res = 0;

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[1] = 1;

	for (int now = 2; now <= n; now++)
	{
		len = 0;
		for (int prev = now - 1; prev >= 1; prev--)
		{
			if (arr[now] > arr[prev] && len < dp[prev])
				len = dp[prev];
		}
		dp[now] = len + 1;

		if (dp[now] > res)
			res = dp[now];
	}

	cout << res;
}
