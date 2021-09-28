#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, maximum = INT32_MIN, minimum = INT32_MAX;
vector<int> vec;
vector<int> order;
int op[5];

int Calculate(int sum, int now, int idx);

void DFS(int now, int sum)
{
	if (now == n)
	{
		if (sum > maximum)
			maximum = sum;
		if (sum < minimum)
			minimum = sum;

		return;
	}

	for (int idx = 1; idx <= 4; idx++)
	{
		if (op[idx] == 0)
			continue;

		op[idx]--;
		DFS(now + 1, Calculate(sum, now, idx));
		op[idx]++;
	}
}

int Calculate(int sum, int now, int idx)
{
	int res;

	switch (idx)
	{
	case 1:
		res = sum + vec[now + 1];
		break;
	case 2:
		res = sum - vec[now + 1];
		break;
	case 3:
		res = sum * vec[now + 1];
		break;
	case 4:
		res = sum / vec[now + 1];
		break;
	}

	return res;
}

int main(void)
{
	cin >> n;

	vec.resize(n+1);
	order.resize(n);

	for (int i = 1; i <= n; i++)
		std::cin >> vec[i];

	for (int i = 1; i <= 4; i++)
		std::cin >> op[i];

	DFS(1, vec[1]);

	cout << maximum << endl;
	cout << minimum << endl;
}