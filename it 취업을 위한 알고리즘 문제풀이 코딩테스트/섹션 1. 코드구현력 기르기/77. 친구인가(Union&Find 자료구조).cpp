#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, d1, d2, start, dest;
int uni[1001];

int Find(int idx)
{
	if (uni[idx] == idx)
		return idx;
	else
		return Find(uni[idx]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a != b)
		uni[a] = b;
}

int main(void)
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		uni[i] = i;

	for (int i = 1; i <= m; i++)
	{
		cin >> d1 >> d2;
		Union(d1, d2);
	}

	cin >> start >> dest;

	if (Find(start) == Find(dest))
		cout << "YES";
	else
		cout << "NO";
}
