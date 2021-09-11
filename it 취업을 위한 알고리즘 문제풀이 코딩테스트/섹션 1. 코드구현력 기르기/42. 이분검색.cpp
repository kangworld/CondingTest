#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m, lt = 0, rt, mid;

	cin >> n >> m;
	rt = n - 1;

	vector<int> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	while (lt <= rt)
	{
		mid = rt + lt / 2;

		if (v[mid] == m)
		{
			cout << mid + 1;
			return 0;
		}
		else if (v[mid] > m)
		{
			rt = mid - 1;
		}
		else
		{
			lt = mid + 1;
		}
	}
}