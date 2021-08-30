#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;

	cin >> n;

	vector<int> ability(n);
	vector<int> rank(n, 1);

	for (int i = 0; i < n; i++)
		cin >> ability[i];

	for (int i = n - 1; i >= 1; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (ability[j] >= ability[i])
				rank[i]++;
		}
	}

	for (int i = 0; i < n; i++)
		cout << rank[i] << " ";
}
