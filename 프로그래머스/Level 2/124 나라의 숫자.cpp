#include <string>
#include <vector>

using namespace std;

string solution(int n)
{
    string answer = "";
    vector<char> nv = { '4', '1', '2' };

    while (n > 0)
    {
        int tmp = n % 3;
        answer = nv[tmp] + answer;

        if (tmp == 0) n = n / 3 - 1;
        else n = n / 3;
    }

    return answer;
}