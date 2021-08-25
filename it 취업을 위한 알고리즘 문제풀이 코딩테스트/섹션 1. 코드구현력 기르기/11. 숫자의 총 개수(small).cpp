#include <iostream>

using namespace std;

int count_num(int num)
{
	int count = 0;

	while (num > 0)
	{
		num = num / 10;
		count++;
	}
	return count;
}

int main()
{
	int num, count = 0;
	
	cin >> num;

	for (int i = 1; i <= num; i++)
	{
		count += count_num(i);
	}

	cout << count;
}