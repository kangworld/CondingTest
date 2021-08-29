#include <iostream>
#include <vector>

using namespace std;

// 짠 코드인데 타임 리밋이 발생
int main()
{
	//freopen("input.txt", "rt", stdin);
	
	int n, k, sum, max = -2000000;

	cin >> n >> k;

	int* arr = new int[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i + k <=  n; i++)
	{
		sum = 0;
		for (int j = i; j < i + k; j++)
		{
			sum += arr[j];
		}
		if (sum > max) max = sum;
	}

	cout << max;
}

//강의 코드
//int main()
//{
//	//freopen("input.txt", "rt", stdin);
//	
//	int n, k, sum = 0, max = -2000000;
//
//	cin >> n >> k;
//
//	vector<int> arr(n);
//
//	for (int i = 0; i < n; i++)
//		cin >> arr[i];
//
//	for (int i = 0; i < k; i++)
//		sum += arr[i];
//
//	for (int i = k; i < n; i++)
//	{
//		sum += arr[i] - arr[i - k];
//		if (sum > max) max = sum;
//	}
//
//	cout << max;
//}

