#include <string>
#include <iostream>

using namespace std;

int solution(string dirs)
{
    int answer = 0;
    int dirY[4] = { -1, 1, 0, 0 };
    int dirX[4] = { 0, 0, -1, 1 };
    bool map[11][11][4] = { false, };
    int nowY = 5, nowX = 5, nextY = 5, nextX = 5, nowDir, nextDir;

    for (int i = 0; i < dirs.size(); i++)
    {
        switch (dirs[i])
        {
        case 'U':
            nowDir = 0, nextDir = 1;
            break;
        case 'D':
            nowDir = 1, nextDir = 0;
            break;
        case 'L':
            nowDir = 2, nextDir = 3;
            break;
        case 'R':
            nowDir = 3, nextDir = 2;
            break;
        }

        nextY = nowY + dirY[nowDir];
        nextX = nowX + dirX[nowDir];

        if (nextY < 0 || nextY > 10 || nextX < 0 || nextX > 10)
            continue;

        if (!map[nowY][nowX][nowDir])
        {
            map[nowY][nowX][nowDir] = true;
            map[nextY][nextX][nextDir] = true;
            answer++;
        }
        nowY = nextY, nowX = nextX;
    }

    return answer;
}