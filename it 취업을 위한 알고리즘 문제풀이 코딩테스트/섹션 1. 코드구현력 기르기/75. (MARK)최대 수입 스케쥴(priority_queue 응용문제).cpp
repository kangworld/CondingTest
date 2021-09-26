#include <iostream>
#include <queue>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.second > b.second;
}

int main(void)
{
	int n, m, d, max, pos = 0, res = 0;

	priority_queue<int> pq;
	vector<pair<int, int>> v;

 	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> m >> d;

		v.push_back(make_pair(m, d));
	}

	sort(v.begin(), v.end(), cmp);

	max = v[0].second;
	for (int day = max; day > 0; day--)
	{
		for ( ; pos < n; pos++)
		{
			if (v[pos].second != day) break;
			pq.push(v[pos].first);
		}

		if (!pq.empty())
		{
			res += pq.top();
			pq.pop();
		}
	}

	cout << res;

	return 0;
}
