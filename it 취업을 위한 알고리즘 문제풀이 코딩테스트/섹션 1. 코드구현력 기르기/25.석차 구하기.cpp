#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;

	cin >> n;

	vector<int> scores(n);
	vector<int> ranks(n, 1);

	for (int i = 0; i < n; i++)
		cin >> scores[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (scores[i] < scores[j])
				ranks[i]++;
		}
	}

	for (int i = 0; i < n; i++)
		cout << ranks[i] << " ";
}
