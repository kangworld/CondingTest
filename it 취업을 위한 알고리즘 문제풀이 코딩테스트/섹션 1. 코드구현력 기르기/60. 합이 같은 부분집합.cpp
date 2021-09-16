#include <iostream>
#include <vector>
using namespace std;

int b[11];
int total = 0;
bool isEqual = false;
int n;

void DFS(int level, int sum)
{
	if (isEqual) return;

	if (level == n + 1)
	{
		if (total - sum == sum)
			isEqual = true;

		return;
	}

	
	DFS(level + 1, sum + b[level + 1]);
	DFS(level + 1, sum);
}

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
		total += b[i];
	}

	DFS(1, 0);

	if (isEqual)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}