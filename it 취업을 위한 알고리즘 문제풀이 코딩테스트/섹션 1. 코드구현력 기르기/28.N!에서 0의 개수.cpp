#include <iostream>
#include <vector>

using namespace std;

//int GetFactorial(int num)
//{
//	if (num == 1)
//		return 1;
//	else
//		return num * GetFactorial(num - 1);
//}
//
//int main()
//{
//	int n, fac, res = 0;
//	
//	cin >> n;
//
//	fac = GetFactorial(n);
//
//	while (true)
//	{
//		if (fac % 10 == 0)
//		{
//			res++;
//			fac /= 10;
//		}
//		else
//			break;
//	}
//
//	cout << res;
//}

int main()
{
	int n, res;

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

	res = vec[2] <= vec[5] ? vec[2] : vec[5];

	cout << res;
}