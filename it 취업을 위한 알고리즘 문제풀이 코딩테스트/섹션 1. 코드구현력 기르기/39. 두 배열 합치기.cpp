#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m, pos1 = 0, pos2 = 0, pos3 = 0;

	cin >> n;
	
	vector<int> v1(n);
	
	for (int i = 0; i < n; i++)
		cin >> v1[i];

	cin >> m;

	vector<int> v2(m);
	vector<int> v3(n + m);

	for (int i = 0; i < m; i++)
		cin >> v2[i];

	while (pos1 < n && pos2 < m)
	{
		if (v1[pos1] < v2[pos2])
			v3[pos3++] = v1[pos1++];
		else
			v3[pos3++] = v2[pos2++];
	}

	while (pos1 < n)
		v3[pos3++] = v1[pos1++];
	while (pos2 < m)
		v3[pos3++] = v2[pos2++];
	
	for (int i = 0; i < pos3; i++)
		cout << v3[i];
}