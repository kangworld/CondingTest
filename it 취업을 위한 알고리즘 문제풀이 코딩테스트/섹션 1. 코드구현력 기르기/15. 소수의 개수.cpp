#include <iostream>

using namespace std;

//int main()
//{
//	int num, count = 0;
//
//	cin >> num;
//
//	int* arr = new int[num + 1]{ 0, };
//
//	for (int i = 2; i <= num; i++)
//	{
//		for (int j = i; j <= num; j += i)
//			arr[j]++;
//	}
//
//	for (int i = 2; i <= num; i++)
//	{
//		if (arr[i] == 1)
//			count++;
//	}
//
//	cout << count;
//}

int main()
{
	int num, count = 0;
	bool flag;

	cin >> num;

	for (int i = 2; i <= num; i++)
	{
		flag = true;
		for (int j = i; j * j <= num; j++)
		{
			if (num % j == 0)
			{
				flag = false;
				break;
			}
		}
		if (flag == true) count++;
	}

	cout << count;
}