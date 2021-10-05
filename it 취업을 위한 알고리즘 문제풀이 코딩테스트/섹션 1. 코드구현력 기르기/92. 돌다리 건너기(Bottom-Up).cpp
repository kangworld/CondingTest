#include <iostream>

using namespace std;

int line[46];
int n;

int DP(int now)
{
	if (now == 1 || now == 2)
		return now;

	if (line[now])
		return line[now];

	return line[now] = DP(now - 1) + DP(now - 2);
}

int main()
{
	cin >> n;

	cout << DP(n+1);
}
