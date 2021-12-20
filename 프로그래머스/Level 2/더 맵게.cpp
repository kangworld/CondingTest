#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> prq;

    for (int i = 0; i < scoville.size(); i++)
        prq.push(scoville[i]);

    while (prq.top() < K)
    {
        int first = prq.top();
        prq.pop();
        if (prq.empty())
            return -1;

        int second = prq.top();
        prq.pop();

        int mixed = first + second * 2;
        prq.push(mixed);
        answer++;
    }

    return answer;
}