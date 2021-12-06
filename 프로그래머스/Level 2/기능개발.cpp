#include <string>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    int total = progresses.size();
    vector<int> answer;
    queue<int> q;
    int finished = 0;

    for (int i = 0; i < total; i++)
    {
        int day = ceil((100 - progresses[i]) / (double)speeds[i]);

        q.push(day);
    }

    while (!q.empty())
    {
        int cur = q.front();
        int res = 1;
        q.pop();

        while (!q.empty() && cur >= q.front())
        {
            res++;
            q.pop();
        }

        answer.push_back(res);
    }

    return answer;
}