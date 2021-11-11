#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

int maxY, maxX, area, maxArea;
map<int, int> cnt;
vector<vector<bool>> visited;
vector<int> dirY = { -1, 1, 0, 0 };
vector<int> dirX = { 0, 0, -1, 1 };

void BFS(int startY, int startX, int tile, vector<vector<int>> picture)
{
    queue<pair<int, int>> q;
    visited[startY][startX] = true;
    q.push(make_pair(startY, startX));
    area++;
    cnt[area]++;
    while (!q.empty())
    {
        pair<int, int> now = q.front();
        q.pop();

        int nowY = now.first;
        int nowX = now.second;

        for (int i = 0; i < 4; i++)
        {
            int nextY = nowY + dirY[i];
            int nextX = nowX + dirX[i];

            if (nextY < 0 || nextY >= maxY || nextX < 0 || nextX >= maxX)
                continue;
            if (visited[nextY][nextX])
                continue;
            if (picture[nextY][nextX] != tile)
                continue;

            cnt[area]++;
            visited[nextY][nextX] = true;
            q.push(make_pair(nextY, nextX));
        }
    }
}

vector<int> solution(int m, int n, vector<vector<int>> picture)
{
    vector<int> answer(2);
    maxY = m, maxX = n, area = 0, maxArea = 0;
    cnt = map<int, int>();
    visited = vector<vector<bool>>(101, vector<bool>(101, false));

    for (int y = 0; y < m; y++)
        for (int x = 0; x < n; x++)
            if (!visited[y][x] && picture[y][x] != 0)
                BFS(y, x, picture[y][x], picture);

    answer[0] = cnt.size();
    for (auto it : cnt)
        maxArea = maxArea < it.second ? it.second : maxArea;
    answer[1] = maxArea;

    return answer;
}