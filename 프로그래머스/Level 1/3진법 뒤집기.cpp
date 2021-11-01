#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;
    int digit = 1;
    vector<int> v;

    while (n > 0)
    {
        v.push_back(n % 3);
        n = n / 3;
    }

    while (!v.empty())
    {
        answer += v.back() * digit;
        v.pop_back();
        digit *= 3;
    }

    return answer;
}