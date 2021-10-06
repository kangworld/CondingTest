#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct brick
{
	int base;
	int height;
	int weight;

	void Init(int _base, int _height, int _weight)
	{
		base = _base;
		height = _height;
		weight = _weight;
	}

	bool operator<(const brick& b) const
	{
		return base > b.base;
	}
};

vector<brick> bricks(100);
int dp[100];
int n, b, h, w, res = 0, maxi;

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> b >> h >> w;
		bricks[i].Init(b, h, w);
	}

	sort(bricks.begin(), bricks.end());
	dp[0] = bricks[0].height;

	for (int i = 1; i < n; i++)
	{
		maxi = 0;

		for (int j = i - 1; j >= 0; j--)
			if (bricks[i].weight < bricks[j].weight && dp[j] > maxi)
				maxi = dp[j];

		dp[i] = bricks[i].height + maxi;

		if (dp[i] > res)
			res = dp[i];
	}

	cout << res;
}
