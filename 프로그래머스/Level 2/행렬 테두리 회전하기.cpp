#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> answer;
    vector<vector<int>> board(rows + 1, vector<int>(columns + 1));

    for (int y = 1; y <= rows; y++)
        for (int x = 1; x <= columns; x++)
            board[y][x] = ((y - 1) * columns + x);

    for (int i = 0; i < queries.size(); i++)
    {
        int r1, c1, r2, c2, tmp, mini;
        r1 = queries[i][0], c1 = queries[i][1], r2 = queries[i][2], c2 = queries[i][3];
        tmp = mini = board[r1][c1];

        //좌측
        for (int y = r1; y < r2; y++)
        {
            board[y][c1] = board[y + 1][c1];
            mini = min(mini, board[y][c1]);
        }

        // 하단
        for (int x = c1; x < c2; x++)
        {
            board[r2][x] = board[r2][x + 1];
            mini = min(mini, board[r2][x]);
        }

        //우측
        for (int y = r2; y > r1; y--)
        {
            board[y][c2] = board[y - 1][c2];
            mini = min(mini, board[y][c2]);
        }

        //상단
        for (int x = c2; x > c1; x--)
        {
            board[r1][x] = board[r1][x - 1];
            mini = min(mini, board[r1][x]);
        }

        board[r1][c1 + 1] = tmp;
        answer.push_back(mini);
    }
    return answer;
}