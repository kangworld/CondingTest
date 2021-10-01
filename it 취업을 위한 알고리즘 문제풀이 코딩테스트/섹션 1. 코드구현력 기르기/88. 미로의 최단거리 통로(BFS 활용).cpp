#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

int res= 999;
bool isDest = false;
int map[8][8];
int dist[8][8];
bool visited[8][8];
//╩С го аб ©Л
int dirY[4] = { -1, 1, 0, 0 };
int dirX[4] = { 0, 0, -1, 1 };


void BFS()
{
	queue<pair<int, int>> q;

	q.push(make_pair(1, 1));
	visited[1][1] = true;
	dist[1][1] = 0;

	while (!q.empty())
	{
		pair<int, int> now = q.front();
		int nowY = now.first;
		int nowX = now.second;

		if (nowY == 7 && nowX == 7)
		{
			isDest = true;
			break;
		}

		q.pop();

		for (int i = 0; i < 3; i++)
		{
			int nextY = nowY + dirY[i];
			int nextX = nowX + dirX[i];

			if (nextY < 1 || nextY > 7 || nextX < 1 || nextX > 7)
				continue;

			if (visited[nextY][nextX])
				continue;

			if (map[nextY][nextX] == 1)
				continue;

			q.push(make_pair(nextY, nextX));
			visited[nextY][nextX] = true;
			dist[nextY][nextX] = dist[nowY][nowX] + 1;
		}
	}

	if (isDest)
		cout << dist[7][7];
	else
		cout << -1;
	
}

int main(void)
{
	for (int i = 1; i <= 7; i++)
	{
		for (int j = 1; j <= 7; j++)
		{
			cin >> map[i][j];
		}
	}

	BFS();
}