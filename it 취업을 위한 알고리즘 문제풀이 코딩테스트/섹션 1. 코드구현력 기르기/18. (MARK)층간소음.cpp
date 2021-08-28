#include <iostream>

using namespace std;

int main()
{
	int n, m, max = -1, stack =0;

	cin >> n >> m;

	int* arr = new int[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > m)
		{
			stack++;
			if (max < stack) max = stack;
		}
		else
			stack = 0;
	}
	cout << max;
}

//배열을 안쓴 버전..강의를 통해 영감을 얻음 하지만 배열을 안쓸 뿐 로직은 비슷
//int main()
//{
//	int n, m, val, max = -1, stack = 0;
//
//	cin >> n >> m;
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> val;
//
//		if (val > m)
//		{
//			stack++;
//			if (stack > max) max = stack;
//		}
//		else
//			stack = 0;
//	}
//	cout << max;
//}