#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int uni[26];

int Find(int a)
{
	if (a == uni[a]) return a;
	else return Find(uni[a]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a != b)
		uni[a] = b;
}

bool IsUnion(int a, int b)
{
	if (Find(a) == Find(b))
		return true;
	else
		return false;
}

struct road
{
	int start;
	int dest;
	int cost;

	road(int _start, int _dest, int _cost)
	{
		start = _start;
		dest = _dest;
		cost = _cost;
	}

	bool operator<(const road& a) const
	{
		return this->cost > a.cost;
	}
};

int main(void)
{
	int n, m, start, dest, cost, res = 0;
	priority_queue<road> pqr;

	cin >> n >> m;

	for (int i = 1; i < n; i++)
	{
		uni[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> start >> dest >> cost;
		road r(start, dest, cost);
		pqr.push(r);
	}

	while (!pqr.empty())
	{
		road r = pqr.top();
		pqr.pop();

		if (IsUnion(r.start, r.dest))
			continue;

		Union(r.start, r.dest);
		res += r.cost;
	}

	cout << res;
}