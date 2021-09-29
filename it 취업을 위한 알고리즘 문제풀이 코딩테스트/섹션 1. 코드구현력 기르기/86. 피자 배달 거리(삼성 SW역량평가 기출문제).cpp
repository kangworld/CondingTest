#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

int n, m, type, mini, sum, res = 9999;
int order[50];
vector<pair<int, int>> home;
vector<pair<int, int>> pizza;

void DFS(int now, int idx)
{
	if (now == m)
	{
		sum = 0;
		for (int i = 0; i < home.size(); i++)
		{
			mini = 999;
			for (int j = 0; j < m; j++)
			{
				int y = abs(home[i].first - pizza[order[j]].first);
				int x = abs(home[i].second - pizza[order[j]].second);

				if (y + x < mini)
					mini = y + x;
			}
			sum += mini;
		}

		if (sum < res)
			res = sum;

		return;
	}

	for (int i = idx; i < pizza.size(); i++)
	{
		order[now] = i;
		DFS(now + 1, i + 1);
	}

}

int main(void)
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> type;

			if (type == 1)
				home.push_back(make_pair(i, j));
			else if(type == 2)
				pizza.push_back(make_pair(i, j));
		}
	}

	DFS(0 , 0);

	cout << res;
}