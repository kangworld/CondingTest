#include <iostream>
#include <vector>

using namespace std;

int mem[21][21];

int DP(int n, int r)
{
	if (n == r || r == 0)
		return 1;

	if (mem[n][r])
		return mem[n][r];

	return mem[n][r] = DP(n - 1, r - 1) + DP(n - 1, r);
}

int main(void)
{
	int n, r, res;

	cin >> n >> r;

	res = DP(n, r);

	cout << res;

	return 0;
}
