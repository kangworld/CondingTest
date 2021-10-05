#include <iostream>

using namespace std;

int line[46];
int n;

int DP(int now)
{
	if (now == 1)
		return 1;
	else if (now == 2)
		return 2;

	if (line[now])
		return line[now];

	return line[now] = DP(now - 1) + DP(now - 2);
}

int main()
{
	cin >> n;

	cout << DP(n);
}
