#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    int cnt = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (isspace(s[i]))
            cnt = 0;
        else if (cnt & 1)
            s[i] = tolower(s[i]), cnt++;
        else
            s[i] = toupper(s[i]), cnt++;
    }

    return s;
}