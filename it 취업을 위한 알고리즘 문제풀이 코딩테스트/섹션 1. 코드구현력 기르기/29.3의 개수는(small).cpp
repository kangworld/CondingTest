#include <iostream>

using namespace std;

int main()
{
	int n, res = 0;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int temp = i;

		while (temp)
		{
			if (temp % 10 == 3)
				res++;
			
			temp /= 10;
		}
	}

	cout << res;
}