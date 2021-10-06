#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Pos
{
	int y, x;

	void Init(int _y, int _x)
	{
		y = _y;
		x = _x;
	}
};

int n;
int map[21][21];
int dist[21][21];
bool visited[21][21];

int dirY[2] = { 1, 0 };
int dirX[2] = { 0, 1 };

void Dijkstra()
{
	dist[1][1] = map[1][1];

	while (true)
	{
		Pos now;
		now.Init(-1, -1);
		int closest = INT32_MAX;

		for (int y = 1; y <= n; y++)
		{
			for (int x = 1; x <= n; x++)
			{
				if (visited[y][x])
					continue;
				if (dist[y][x] == INT32_MAX)
					continue;

				
				if (closest > dist[y][x])
				{
					now.Init(y, x);
					closest = dist[y][x];
				}
				
			}
		}

		if (now.x == -1)
			break;

		visited[now.y][now.x] = true;

		for (int i = 0; i < 2; i++)
		{
			int nextY = now.y + dirY[i];
			int nextX = now.x + dirX[i];

			if (nextY < 1 || nextY > n || nextX < 1 || nextX > n)
				continue;
			if (visited[nextY][nextX])
				continue;

			int nextDist = dist[now.y][now.x] + map[nextY][nextX];

			if (nextDist < dist[nextY][nextX])
				dist[nextY][nextX] = nextDist;
		}
	}
}

int main()
{
	cin >> n;

	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= n; x++)
		{
			cin >> map[y][x];
			dist[y][x] = INT32_MAX;
		}
	}
		
	Dijkstra();

	cout << dist[n][n];
}
