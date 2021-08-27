#include <iostream>

using namespace std;

int reverse(int num)
{
	int result = 0;

	while (num > 0)
	{
		result = result * 10 + num % 10;
		num = num / 10;
	}

	return result;
}

bool isPrime(int num)
{
	int count = 0;
	for (int i = 2; i <= num; i++)
		if (num % i == 0)
			count++;

	return count == 1 ? true : false;
}

//bool isPrime(int num)
//{
//	int count = 0;
//	bool flag = true;
//	for (int i = 2; i < num; i++)
//		if (num % i == 0)
//		{
//			flag = false;
//			break;
//		}
//
//	return flag;
//}

int main()
{
	int count, number;

	cin >> count;

	for (int i = 0; i < count; i++)
	{
		cin >> number;

		number = reverse(number);

		if (isPrime(number))
			cout << number << " ";
	}
}