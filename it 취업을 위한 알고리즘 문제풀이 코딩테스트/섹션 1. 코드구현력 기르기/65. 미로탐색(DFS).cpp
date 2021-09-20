#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[8][8];
bool visited[8][8];
int dirY[4] = { -1, 1, 0 , 0 };
int dirX[4] = { 0, 0, -1, 1 };
int res = 0;

void DFS(int y, int x)
{
	if (y == 7 && x == 7)
	{
		res++;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nextY = y + dirY[i];
		int nextX = x + dirX[i];

		if (nextY < 1 || nextY > 7 || nextX < 1 || nextX > 7)
			continue;

		if (map[nextY][nextX] || visited[nextY][nextX])
			continue;

		visited[nextY][nextX] = true;
		DFS(nextY, nextX);
		visited[nextY][nextX] = false;
	}
}

int main()
{
	for (int i = 1; i <= 7; i++)
		for (int j = 1; j <= 7; j++)
			cin >> map[i][j];

	visited[1][1] = true;
	DFS(1, 1);

	cout << res;
}