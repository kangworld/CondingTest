#include <iostream>

using namespace std;

bool a[11];
int n;

void DFS(int level)
{
	if (level > n)
	{
		for (int i = 1; i <= n; i++)
		{
			if (a[i])
				cout << i << " ";
		}
		cout << endl;
		return;
	}

	a[level] = true;
	DFS(level + 1);
	a[level] = false;
	DFS(level + 1);
}

int main()
{
	cin >> n;

	DFS(1);
}