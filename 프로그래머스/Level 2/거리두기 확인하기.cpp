#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Developer
{
    int y, x, dist;

    Developer(int _y, int _x, int _dist)
    {
        y = _y;
        x = _x;
        dist = _dist;
    }
};

bool BFS(int room, int startY, int startX, vector<vector<string>> places)
{
    //╩С го аб ©Л
    vector<int> dirY = { -1, 1, 0, 0 };
    vector<int> dirX = { 0, 0, -1, 1 };
    bool visited[5][5] = { false, };

    visited[startY][startX] = true;
    queue<Developer> q;
    q.push({ startY, startX, 0 });

    while (!q.empty())
    {
        Developer now = q.front();
        q.pop();

        if (now.dist > 2)
            return false;

        for (int i = 0; i < 4; i++)
        {
            int nextY = now.y + dirY[i];
            int nextX = now.x + dirX[i];

            if (nextY < 0 || nextY > 4 || nextX < 0 || nextX > 4)
                continue;
            if (visited[nextY][nextX])
                continue;
            if (places[room][nextY][nextX] == 'X')
                continue;

            int nextDist = now.dist + 1;
            if (places[room][nextY][nextX] == 'P' && nextDist <= 2)
                return true;

            visited[nextY][nextX] = true;
            q.push({ nextY, nextX, nextDist });
        }
    }
    return false;
}

vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;

    for (int i = 0; i < places.size(); i++)
    {
        int inValid = false;
        for (int y = 0; y < 5; y++)
        {
            for (int x = 0; x < 5; x++)
            {
                if (places[i][y][x] == 'P')
                    inValid = BFS(i, y, x, places);

                if (inValid) break;
            }
            if (inValid) break;
        }
        if (inValid) answer.push_back(0);
        else answer.push_back(1);
    }

    return answer;
}