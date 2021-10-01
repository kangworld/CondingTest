#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

const int EMPTY = -1;
const int UNRIPE = 0;
const int RIPE = 1;

struct pos
{
	int y;
	int x;

	pos(int _y, int _x)
	{
		y = _y;
		x = _x;
	}
};

//╩С го аб ©Л
int dirY[4] = { -1, 1, 0, 0 };
int dirX[4] = { 0, 0, -1, 1 };

int n, m, res;
int tomato[1001][1001];
int day[1001][1001];
queue<pos> q;

void BFS()
{
	while (!q.empty())
	{
		pos now = q.front();
		int nowY = now.y;
		int nowX = now.x;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextY = nowY + dirY[i];
			int nextX = nowX + dirX[i];

			if (nextY < 1 || nextY > n || nextX < 1 || nextX > m)
				continue;

			if (tomato[nextY][nextX] == EMPTY || tomato[nextY][nextX] == RIPE)
				continue;

			q.push(pos(nextY, nextX));
			tomato[nextY][nextX] = RIPE;
			day[nextY][nextX] = day[nowY][nowX] + 1;
		}
	}
}

int main(void)
{
	cin >> m >> n;

	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= m; x++)
		{
			cin >> tomato[y][x];

			if (tomato[y][x] == RIPE)
				q.push(pos(y, x));
		}
	}

	BFS();

	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= m; x++)
		{
			if (tomato[y][x] == UNRIPE)
			{
				cout << -1;
				return 0;
			}
		}
	}

	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= m; x++)
		{
			if (res < day[y][x])
				res = day[y][x];
		}
	}
		
	cout << res;

	return 0;
}