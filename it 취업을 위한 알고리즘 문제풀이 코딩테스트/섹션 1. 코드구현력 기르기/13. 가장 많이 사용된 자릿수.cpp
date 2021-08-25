#include <iostream>

using namespace std;

int main()
{
	string str;
	int arr[10] = { 0, };
	int max = 0, result;

	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		arr[str[i] - '0']++;
	}

	for (int i = 0; i <= 9; i++)
	{
		if (arr[i] >= max)
		{
			max = arr[i];
			result = i;
		}
	}

	cout << result;
}