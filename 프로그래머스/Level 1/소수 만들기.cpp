#include <vector>
#include <iostream>
using namespace std;

int answer = 0;
vector<int> v;

void DFS(int now, int pos, int sum)
{
    if (now == 3)
    {
        for (int i = 2; i < sum; i++)
            if (sum % i == 0)
                return;

        answer++;
        return;
    }

    for (int i = pos; i < v.size(); i++)
        DFS(now + 1, i + 1, sum + v[i]);
}

int solution(vector<int> nums) {
    v = nums;

    DFS(0, 0, 0);

    return answer;
}