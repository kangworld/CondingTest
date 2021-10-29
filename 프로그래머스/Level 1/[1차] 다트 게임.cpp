#include <string>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int solution(string dartResult)
{
    int answer = 0;
    int pos = 1, sum = 0;
    vector<int> sums(4, 0);

    for (int i = 0; i < dartResult.size(); i++)
    {
        if (dartResult[i] >= '0' && dartResult[i] <= '9')
            sum = sum * 10 + (dartResult[i] - '0');
        else if (dartResult[i] == 'S') sums[pos++] = pow(sum, 1), sum = 0;
        else if (dartResult[i] == 'D') sums[pos++] = pow(sum, 2), sum = 0;
        else if (dartResult[i] == 'T') sums[pos++] = pow(sum, 3), sum = 0;
        else if (dartResult[i] == '*')
        {
            sums[pos - 2] *= 2;
            sums[pos - 1] *= 2;
        }
        else if (dartResult[i] == '#')
            sums[pos - 1] = -sums[pos - 1];
    }

    for (int i = 1; i <= 3; i++)
        answer += sums[i];

    return answer;
}