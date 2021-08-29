#include <iostream>
#include <vector>

using namespace std;

//int main()
//{
//	//freopen("input.txt", "rt", stdin);
//	
//	int n, max = 0, stack = 1;
//
//	cin >> n;
//
//	vector<int> v(n);
//	
//	for (int i = 0; i < n; i++)
//		cin >> v[i];
//
//	for (int i = 0; i < n - 1; i++)
//	{
//		if (v[i + 1] >= v[i])
//		{
//			stack++;
//			if (stack > max) max = stack;
//		}
//		else
//			stack = 1;
//	}
//
//	cout << max;
//}

int main()
{
	freopen("input.txt", "rt", stdin);

	int n, pre, max = 0, stack = 1;

	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	pre = v[0];
	for (int i = 1; i < n; i++)
	{
		if (v[i] >= pre)
		{
			stack++;
			if (stack > max) max = stack;
		}
		else
			stack = 1;

		pre = v[i];
	}

	cout << max;
}

