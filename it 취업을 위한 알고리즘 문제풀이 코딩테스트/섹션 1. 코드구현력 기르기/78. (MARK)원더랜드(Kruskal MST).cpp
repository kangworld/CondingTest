#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct node
{
	int start;
	int dest;
	int cost;

	node(int start, int dest, int cost)
	{
		this->start = start;
		this->dest = dest;
		this->cost = cost;
	}

	bool operator<(const node &a)
	{
		return cost < a.cost;
	}
};

int uni[26];
vector<node> nd;
int n, m, start, dest, cost, res = 0;

int Find(int a)
{
	if (a == uni[a])
		return a;
	else
		return Find(uni[a]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a != b) uni[a] = b;
}

bool IsUnion(int a, int b)
{
	if (Find(a) == Find(b))
		return true;
	else
		return false;
}

int main(void)
{
	queue<int> path;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		uni[i] = i;

	for (int i = 1; i <= m; i++)
	{
		cin >> start >> dest >> cost;
		nd.push_back(node(start, dest, cost));
	}

	sort(nd.begin(), nd.end());

	for(int i = 0; i < m; i++)
	{
		if (!IsUnion(nd[i].start, nd[i].dest))
		{
			res += nd[i].cost;
			Union(nd[i].start, nd[i].dest);
		}
	}

	cout << res;
}