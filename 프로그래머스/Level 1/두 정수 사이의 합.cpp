#include <algorithm>

using namespace std;

long long solution(int _a, int _b)
{
    long long answer = 0;
    int a = min(_a, _b);
    int b = max(_a, _b);

    for (int i = a; i <= b; i++)
        answer += i;

    return answer;
}