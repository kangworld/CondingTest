#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isBalance(string str)
{
    stack<char> s;

    for (int i = 0; i < str.size(); i++)
    {
        if (!s.empty() && s.top() == '(' && str[i] == ')') s.pop();
        else s.push(str[i]);
    }

    return s.empty() ? true : false;
}

string recursive(string str)
{
    if (str.empty()) return str;

    string u, v;
    int cnt = 0;

    // split w to u and v
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(') cnt++;
        else cnt--;

        if (cnt == 0)
        {
            u = str.substr(0, i + 1);
            v = str.substr(i + 1);
            break;
        }
    }

    if (isBalance(u)) return u + recursive(v);

    for (char& c : u) c = c == '(' ? ')' : '(';
    return "(" + recursive(v) + ")" + u.substr(1, u.size() - 2);
}

string solution(string p)
{
    return recursive(p);
}