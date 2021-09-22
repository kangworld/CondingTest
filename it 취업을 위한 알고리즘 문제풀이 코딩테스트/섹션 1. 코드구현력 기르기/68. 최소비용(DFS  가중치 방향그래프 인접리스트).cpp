#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int n, m, n1, n2, cost, res = 9999;

//first : node 
//second : cost
vector<vector<pair<int, int>>> vec(21);
int visited[21];


void DFS(int now, int sum)
{
	if (now == n)
	{
		res = sum < res ? sum : res;
		return;
	}

	for (pair<int, int> p : vec[now])
	{
		if (visited[p.first])
			continue;

		visited[p.first] = true;
		DFS(p.first, sum + p.second);
		visited[p.first] = false;
	}

}

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		cin >> n1 >> n2 >> cost;

		vec[n1].push_back(make_pair(n2, cost));
	}

	visited[1] = true;
	DFS(1, 0);

	cout << res;
}