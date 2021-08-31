#include <iostream>
#include <vector>

using namespace std;

int main()
{
	string str;
	int hCount = 0, cCount = 0, res = 1, pos;

	cin >> str;

	if (str[1] == 'H')
	{
		cCount = 1;
		pos = 1;
	}
	else
	{
		int i;
		for (i = 1; str[i] != 'H'; i++)
		{
			cCount = cCount * 10 + (str[i] - '0');
		}
		pos = i;
	}

	if (str[pos + 1] == '\0')
	{
		hCount = 1;
	}
	else
	{
		for (int j = pos + 1; str[j] != '\0'; j++)
		{
			hCount = hCount * 10 + (str[j] - '0');
		}
	}

	res = cCount * 12 + hCount;
	cout << res;
}