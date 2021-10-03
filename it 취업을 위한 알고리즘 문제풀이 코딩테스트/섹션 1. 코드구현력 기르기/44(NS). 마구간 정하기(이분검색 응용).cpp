#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int GetHorseCount(vector<int> stableX, int length)
{
	int res = 1, pos = stableX[0];

	for (int i = 1; i < stableX.size(); i++)
	{
		if (stableX[i] - pos >= length)
		{
			res++;
			pos = stableX[i];
		}
	}

	return res;
}

int main()
{
	int n, m, lt = 1, rt, mid, res;

	cin >> n >> m;

	vector<int> stableX(n);

	for (int i = 0; i < n; i++)
		cin >> stableX[i];

	sort(stableX.begin(), stableX.end());
	rt = stableX[n - 1];

	while (lt <= rt)
	{
		mid = (lt + rt) / 2;
		
		if (GetHorseCount(stableX, mid) >= m)
		{
			lt = mid + 1;
			res = mid;
		}
		else
			rt = mid - 1;
	}

	cout << res;
}
