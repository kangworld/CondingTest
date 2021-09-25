#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int main(void)
{
	int n, k, now, count = 0;
	queue<int> q;

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		q.push(i);

	while (q.size() > 0)
	{
		now = q.front();
		q.pop();

		count++;

		if (count == k)
			count = 0;
		else
			q.push(now);
	}

	cout << now;
}
