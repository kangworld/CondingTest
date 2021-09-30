#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

const int SEA = 0;
const int ISLAND = 1;

int n, res;
int map[21][21];
bool visited[21][21];

// ╩С го аб ©Л ╩Саб ╩С©Л гоаб го©Л
int dirY[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dirX[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };

void BFS(int y, int x)
{
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	visited[y][x] = true;

	while (!q.empty())
	{
		pair<int, int> now = q.front();
		int nowY = now.first;
		int nowX = now.second;

		q.pop();
		
		for (int i = 0; i < 8; i++)
		{
			int nextY = nowY + dirY[i];
			int nextX = nowX + dirX[i];

			if (nextY < 1 || nextY > n || nextX < 1 || nextX > n)
				continue;

			if (visited[nextY][nextX])
				continue;

			if (map[nextY][nextX] != ISLAND)
				continue;

			q.push(make_pair(nextY, nextX));
			visited[nextY][nextX] = true;
		}
	}

	res++;
}

int main(void)
{
	cin >> n;

	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= n; x++)
			cin >> map[y][x];

	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= n; x++)
		{
			if(!visited[y][x] && map[y][x] == ISLAND)
				BFS(y, x);
		}

	cout << res;
}