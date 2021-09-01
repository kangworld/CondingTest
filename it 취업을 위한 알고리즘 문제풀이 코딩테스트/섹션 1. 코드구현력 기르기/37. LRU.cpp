#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int s, n, i, j, k, taskID;
	bool hit;
	
	cin >> s >> n;

	vector<int> v(s, 0);


	for (i = 0; i < n; i++)
	{
		hit = false;
		cin >> taskID;

		for (j = 0; j < s; j++)
		{
			if (v[j] == taskID)
			{
				hit = true;
				break;
			}
		}

		if (hit)
		{
			for (k = j; k >= 1; k--)
				v[k] = v[k - 1];
		}
		else
		{
			for (k = s - 1; k >= 1; k--)
				v[k] = v[k - 1];
		}

		v[0] = taskID;
	}


	for (int i = 0; i < s; i++)
		cout << v[i] << " ";
}