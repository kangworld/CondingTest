#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct node
{
	int dest;
	int cost;

	node(int _dest, int _cost)
	{
		dest = _dest;
		cost = _cost;
	}

	bool operator<(const node& a) const
	{
		return this->cost > a.cost;
	}
};

int main(void)
{
	int n, m, start, dest, cost, count = 0, res = 0;
	bool visited[26] = { false, };
	vector<node> ndv[26];
	priority_queue<node> pq;

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> start >> dest >> cost;

		ndv[start].push_back(node(dest, cost));
		ndv[dest].push_back(node(start, cost));
	}

	pq.push(node(1, 0));

	while (pq.empty() || count != n)
	{
		node tn = pq.top();
		pq.pop();

		if (visited[tn.dest])
			continue;

		visited[tn.dest] = true;
		res += tn.cost;
		count++;

		for (node tmp : ndv[tn.dest])
			pq.push(tmp);
	}

	cout << res;
}