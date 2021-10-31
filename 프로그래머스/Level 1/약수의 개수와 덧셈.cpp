#include <string>
#include <vector>

using namespace std;

int solution(int left, int right)
{
    int answer = 0;
    vector<int> divisor(1001, 1);

    for (int i = 2; i <= right; i++)
    {
        for (int j = 1; j * i <= right; j++)
        {
            divisor[j * i]++;
        }
    }

    for (int i = left; i <= right; i++)
    {
        if (divisor[i] % 2 == 0)
            answer += i;
        else
            answer -= i;
    }

    return answer;
}