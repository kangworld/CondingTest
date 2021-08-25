#include <iostream>

using namespace std;

int digit_sum(int num)
{
	int sum = 0;

	while (num > 0)
	{
		sum += num % 10;
		num = num / 10;
	}

	return sum;
}

int main()
{
	int count, num, maxNum, sum = 0, maxSum = 0;
	
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		cin >> num;
		
		int tmpNum = num;

		sum = digit_sum(num);

		if (sum > maxSum)
		{
			maxSum = sum;
			maxNum = tmpNum;
		}
		
		if (sum == maxSum)
		{
			maxNum = tmpNum > maxNum ? tmpNum : maxNum;
		}
	}

	cout << maxNum;
}


//int main()
//{
//	int count, num, maxNum, sum = 0, maxSum = 0;
//
//	cin >> count;
//
//	for (int i = 0; i < count; i++)
//	{
//		cin >> num;
//
//		sum = digit_sum(num);
//
//		if (sum > maxSum)
//		{
//			maxSum = sum;
//			maxNum = num;
//		}
//		else if (sum == maxSum)
//		{
//			maxNum = num > maxNum ? num : maxNum;
//		}
//	}
//
//	cout << maxNum;
//}
