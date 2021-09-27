#include <iostream>
#include <queue>

using namespace std;

struct cmp
{
	bool operator()(int a, int b)
	{
		return a < b;
	}
};

int main(void)
{
	priority_queue<int, vector<int>, cmp> pq;
	int input;

	while (true)
	{
		cin >> input;

		switch (input)
		{
		case -1 :
			return 0;
		case 0 :
			if (pq.size() == 0)
				cout << "-1";
			else
			{
				cout << pq.top() << endl;
				pq.pop();
			}
			break;
		default:
			pq.push(input);
			break;
		}
	}
}
