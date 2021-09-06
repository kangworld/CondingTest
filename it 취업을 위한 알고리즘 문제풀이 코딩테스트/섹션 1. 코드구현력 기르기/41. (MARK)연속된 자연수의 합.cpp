#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, tmp, count = 1, res = 0;

	cin >> n;

	tmp = n;
	n--;

	while (n > 0)
	{
		count++;
		n -= count;

		if (n % count == 0)
		{
			res++;
			for (int i = 1; i < count; i++)
				cout << i + (n / count) << " + ";

			cout << count + (n / count) << " = " << tmp << endl;;
		}
	}

	cout << res;
}