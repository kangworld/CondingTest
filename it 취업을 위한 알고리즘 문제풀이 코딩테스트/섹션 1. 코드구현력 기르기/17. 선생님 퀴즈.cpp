#include <iostream>

using namespace std;

int rec_sum(int num) {
	if (num == 1)
		return num;
	
	return num + rec_sum(num - 1);
}

int main()
{
	int counts, num, sum;

	cin >> counts;

	for (int i = 0; i < counts; i++)
	{
		cin >> num >> sum;

		if (sum == rec_sum(num))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}