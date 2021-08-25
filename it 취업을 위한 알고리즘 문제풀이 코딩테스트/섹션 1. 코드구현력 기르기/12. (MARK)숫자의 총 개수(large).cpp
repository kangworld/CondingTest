#include <iostream>

using namespace std;

int main()
{
	int num, loop = 1, sum = 0, res = 0, idx = 9;
	
	cin >> num;

	while (sum + idx < num)
	{
		res += idx * loop;
		sum += idx;
		idx = idx * 10;
		loop++;
	}

	res += (num - sum) * loop;

	cout << res;
}