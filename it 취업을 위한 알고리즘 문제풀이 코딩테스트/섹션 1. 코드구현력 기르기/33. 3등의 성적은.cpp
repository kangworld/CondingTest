#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n, tmp, idx, cnt = 0;

	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	for (int i = 0; i < n - 1; i++)
	{
		idx = i;

		for (int j = i + 1; j < n; j++)
		{
			if (v[idx] < v[j])
			{
				idx = j;
			}
		}

		tmp = v[idx];
		v[idx] = v[i];
		v[i] = tmp;
	}

	for (int i = 0; i < n-1; i++)
	{
		if (v[i] != v[i + 1])
			cnt++;

		if (cnt == 2)
		{
			cout << v[i + 1];
			return 0;
		}
	}
}