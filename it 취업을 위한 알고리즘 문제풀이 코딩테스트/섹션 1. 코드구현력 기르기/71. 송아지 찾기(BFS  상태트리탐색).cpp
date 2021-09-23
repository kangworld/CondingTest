#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <math.h>

using namespace std;

///My Code
//int p, c, res;
//
//struct cmp
//{
//	bool operator()(const pair<int, int> a, const pair<int, int> b)
//	{
//		return abs(a.first - c) > abs(b.first - c);
//	}
//};
//
//void BFS(int start)
//{
//	queue<pair<int, int>> q;
//
//	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
//
//	pq.push(make_pair(start, 0));
//
//	while (true)
//	{
//		pair<int, int> now = pq.top();
//		pq.pop();
//
//		if (now.first - c== 0)
//		{
//			res = now.second;
//			break;
//		}
//
//		pq.push(make_pair(now.first + 1, now.second + 1));
//		pq.push(make_pair(now.first - 1, now.second + 1));
//		pq.push(make_pair(now.first + 5, now.second + 1));
//	}
//}
//
//int main()
//{
//	cin >> p >> c;
//
//	BFS(p);
//
//	cout << res;
//}

//Ref Code
int p, c, res;
int visited[10001];
int dir[3] = { 1, -1, 5 };

void BFS(int start)
{
	queue<pair<int, int>> q;

	q.push(make_pair(start, 0));
	visited[start] = true;

	while (true)
	{
		pair<int, int> now = q.front();
		q.pop();

		if (now.first == c)
		{
			res = now.second;
			return;
		}

		for (int i = 0; i < 3; i++)
		{
			if (now.first + dir[i] > 10000 || visited[now.first + dir[i]])
				continue;

			q.push(make_pair(now.first + dir[i], now.second + 1));
			visited[now.first + dir[i]] = true;
		}
	}
}


int main(void)
{
	cin >> p >> c;

	BFS(p);

	cout << res;
}
