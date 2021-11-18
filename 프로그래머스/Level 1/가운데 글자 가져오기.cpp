#include <string>

using namespace std;

string solution(string s)
{
    string answer;
    int mid = s.size() / 2;

    if (s.size() % 2 == 1)
        answer = s[mid];
    else
        answer = s.substr(mid - 1, 2);

    return answer;
}