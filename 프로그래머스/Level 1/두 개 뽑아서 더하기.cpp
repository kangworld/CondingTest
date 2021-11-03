#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> answer;
vector<int> numbers;

void DFS(int now, int pos, int sum)
{
    if (now == 2)
    {
        answer.push_back(sum);
        return;
    }

    for (int i = pos; i < numbers.size(); i++)
        DFS(now + 1, i + 1, sum + numbers[i]);
}

vector<int> solution(vector<int> _numbers)
{
    numbers = _numbers;

    DFS(0, 0, 0);

    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    return answer;
}