#include <iostream>

using namespace std;
int main()
{
	string str, number;
	int result = 0, count = 0;
	cin >> str;

	for (int i = 0; i < str.size(); i++) 
		if (str[i] >= '0' && str[i] <= '9')
			number += str[i];

	for (int i = 0; i < number.size(); i++)
		result = result * 10 + (number[i] - '0');

	cout << result << endl;

	for (int i = 1; i <= result; i++)
		if (result % i == 0)
			count++;

	cout << count;
}