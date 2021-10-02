#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

struct Pos
{
	int y;
	int x;
	int dist;
	
	Pos(int _y, int _x, int _dist)
	{
		y = _y;
		x = _x;
		dist = _dist;
	}
	
	bool operator<(const Pos& p) const
	{
		if (dist == p.dist)
			if (y != p.y)
				return y > p.y;
			else
				return x > p.x;
		else
			return dist > p.dist;
	}
};

struct Lion
{
	int y;
	int x;
	int size;
	int stack;

	Lion(){}

	Lion(int _y, int _x, int _size, int _stack)
	{
		y = _y;
		x = _x;
		size = _size;
		stack = _stack;
	}

	void eat()
	{
		stack++;

		if (stack == size)
			size++, stack = 0;
	}
};

priority_queue<Pos> prq;
Lion simba;
int n, res;
int map[26][26];
bool visited[26][26];

//╩С го аб ©Л
int dirY[4] = { -1, 1, 0, 0 };
int dirX[4] = { 0, 0, -1, 1 };

void BFS()
{
	prq.push(Pos(simba.y, simba.x, 0));

	while (!prq.empty())
	{
		Pos now = prq.top();
		prq.pop();

		int nowY = now.y;
		int nowX = now.x;
		int nowDist = now.dist;

		if (map[nowY][nowX] != 0 && map[nowY][nowX] < simba.size)
		{
			simba.y = nowY;
			simba.x = nowX;
			map[simba.y][simba.x] = 0;
			simba.eat();
			res = nowDist;

			for (int y = 1; y <= n; y++)
				for (int x = 1; x <= n; x++)
					visited[y][x] = false;

			while (!prq.empty())
				prq.pop();
		}


		for (int i = 0; i < 4; i++)
		{
			int nextY = nowY + dirY[i];
			int nextX = nowX + dirX[i];

			if (nextY < 1 || nextY > n || nextX < 1 || nextX > n)
				continue;
			if (visited[nextY][nextX])
				continue;
			if (simba.size < map[nextY][nextX])
				continue;

			visited[nextY][nextX] = true;
			prq.push(Pos(nextY, nextX, nowDist+1));
		}
	}
}

int main(void)
{
	cin >> n;

	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= n; x++)
		{
			cin >> map[y][x];

			if (map[y][x] == 9)
			{
				simba = Lion(y, x, 2, 0);
				map[y][x] = 0;
			}
				
		}
	}

	BFS();

	cout << res;
}