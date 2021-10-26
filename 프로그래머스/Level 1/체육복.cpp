#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) 
{
    int answer = 0;
    vector<int> state(31, 1);

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    for (int i = 0; i < reserve.size(); i++)
        state[reserve[i]] = 2;

    for (int i = 0; i < lost.size(); i++)
        state[lost[i]] = 0;

    for (int i = 0; i < reserve.size(); i++)
    {
        if (state[reserve[i]] == 0)
            state[reserve[i]] = 1;
        else if (state[reserve[i]] == 2)
            if (state[reserve[i] - 1] == 0)
                state[reserve[i] - 1] = 1;
            else if (state[reserve[i] + 1] == 0)
                state[reserve[i] + 1] = 1;
    }

    for (int i = 1; i <= n; i++)
        if (state[i] != 0)
            answer++;

    return answer;
}