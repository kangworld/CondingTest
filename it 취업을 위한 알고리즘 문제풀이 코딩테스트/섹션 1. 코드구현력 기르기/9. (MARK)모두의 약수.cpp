#include <iostream>

// 정답 코드
//using namespace std;
//int main()
//{
//	int num, count;
//	
//	cin >> num;
//
//	for (int i = 1; i <= num; i++)
//	{
//		count = 0;
//
//		for (int j = 1; j <= i; j++)
//		{
//			if (i % j == 0) count++;
//		}
//
//		cout << count << " ";
//	}
//}

using namespace std;

int main()
{
	int num, count;

	cin >> num;

	int *arr = new int[num+1] { 0, };

	for (int i = 1; i <= num; i++)
	{
		for (int j = i; j <= num; j += i)
		{
			arr[j] += 1;
		}
	}

	for (int i = 1; i <= num; i++)
	{
		cout << arr[i] << " ";
	}
}