#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int GetDVDCount(vector<int> songs, int length)
{
	int sum = 0, res = 1;

	for (int i = 0; i < songs.size(); i++)
	{
		if (sum + songs[i] > length)
		{
			sum = 0;
			res++;
		}

		sum += songs[i];
	}

	return res;
}

int main()
{
	int n, m, lt = 1, rt = 0, mid, res, max = 0;

	cin >> n >> m;

	vector<int> songs(n);

	for (int i = 0; i < n; i++)
	{
		cin >> songs[i];
		rt += songs[i];
		if (songs[i] > max) 
			max = songs[i];
	}

	while (lt <= rt)
	{
		mid = (lt + rt) / 2;
		
		if (mid >= max && GetDVDCount(songs, mid) <= m)
		{
			rt = mid - 1;
			res = mid;
		}
		else
			lt = mid + 1;
	}

	cout << res;
}
