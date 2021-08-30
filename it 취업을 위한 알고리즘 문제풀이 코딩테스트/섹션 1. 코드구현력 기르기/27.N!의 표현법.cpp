#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	
	cin >> n;

	vector<int> vec(n + 1, 0);

	for (int i = 2; i <= n; i++)
	{
		int temp = i;
		int div = 2;

		while (true)
		{
			if (temp % div == 0)
			{
				vec[div]++;
				temp /= div;

				if (temp == 1)
					break;
			}
			else
				div++;
		}
	}

	cout << n << "! = ";

	for (int i = 1; i <= n; i++)
		if (vec[i] != 0)
			cout << vec[i] << " ";
}
