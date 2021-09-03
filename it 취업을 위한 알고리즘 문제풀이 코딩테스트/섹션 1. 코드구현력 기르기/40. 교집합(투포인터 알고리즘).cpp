#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m, pos1 = 0, pos2 = 0;

	cin >> n;
	
	vector<int> v1(n);
	
	for (int i = 0; i < n; i++)
		cin >> v1[i];

	cin >> m;

	vector<int> v2(m);

	for (int i = 0; i < m; i++)
		cin >> v2[i];

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	while (pos1 < n && pos2 < m)
	{
		if (v1[pos1] < v2[pos2]) 
			pos1++;
		else if (v1[pos1] > v2[pos2]) 
			pos2++;
		else
		{
			cout << v1[pos1];
			pos1++;
			pos2++;
		}
	}
}