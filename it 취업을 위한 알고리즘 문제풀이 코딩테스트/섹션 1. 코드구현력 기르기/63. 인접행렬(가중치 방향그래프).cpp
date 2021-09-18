#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, m, e1, e2, cost;

	cin >> n >> m;

	vector<vector<int>> vec(n + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= m; i++)
	{
		cin >> e1 >> e2 >> cost;

		vec[e1][e2] = cost;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << vec[i][j] << " ";
		cout << endl;
	}
}