#include <string>
#include <vector>

using namespace std;

int answer = 0;

void DFS(int now, int sum, vector<int> numbers, int target)
{
    if (now == numbers.size())
    {
        if (sum == target)
            answer++;
        return;
    }

    DFS(now + 1, sum + numbers[now], numbers, target);
    DFS(now + 1, sum - numbers[now], numbers, target);
}

int solution(vector<int> numbers, int target)
{
    DFS(0, 0, numbers, target);
    return answer;
}