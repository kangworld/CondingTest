#include <iostream>

using namespace std;

int main()
{
	//freopen("input.txt", "rt", stdin);

	int n, result = 0;
	bool flag;

	cin >> n;
	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n - 1; i++)
	{
		flag = true;

		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] >= arr[i])
			{
				flag = false;
				break;
			}
		}

		if (flag) result++;
	}

	cout << result;
}


//강의 참고 코드
//int main()
//{
//	//freopen("input.txt", "rt", stdin);
//
//	int n, max, result = 0;
//	bool flag;
//
//	cin >> n;
//	int* arr = new int[n];
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//
//	max = arr[n-1];
//
//	for (int i = n-1; i >= 0; i--)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//			result++;
//		}
//	}
//
//	cout << result;
//}
