#include <string>
#include <vector>

using namespace std;

int solution(int n) 
{
    int answer = 0;
    vector<bool> v(n + 1, false);

    for (int i = 2; i <= n; i++)
    {
        if (!v[i])
        {
            for (int j = 2; j * i <= n; j++)
                v[j * i] = true;
            answer++;
        }
    }

    return answer;
}