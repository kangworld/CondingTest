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

//�迭�� �Ⱦ� ����..���Ǹ� ���� ������ ���� ������ �迭�� �Ⱦ� �� ������ ���
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