#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include <sstream>

using namespace std;

vector<bool> visited(3);
long long answer;

string calc(string a, string b, string op)
{
    long long c = stoll(a);
    long long d = stoll(b);
    string res;

    if (op == "+")
        res = to_string(c + d);
    else if (op == "-")
        res = to_string(c - d);
    else if (op == "*")
        res = to_string(c * d);

    return res;
}

void DFS(int now, string perm, string ops, vector<string> exp)
{
    if (now == 3)
    {
        for (int i = 0; i < 3; i++)
        {
            string op(1, perm[i]);

            for (int j = 0; j < exp.size();)
            {
                if (op == exp[j])
                {
                    string res = calc(exp[j - 1], exp[j + 1], exp[j]);
                    exp[j] = res;
                    exp.erase(exp.begin() + (j + 1));
                    exp.erase(exp.begin() + (j - 1));
                }
                else
                    j++;
            }
        }

        long long res = abs(stoll(exp.front()));
        answer = res > answer ? res : answer;
    }

    for (int i = 0; i < 3; i++)
    {
        if (visited[i]) continue;

        visited[i] = true;
        DFS(now + 1, perm + ops[i], ops, exp);
        visited[i] = false;
    }
}

long long solution(string expression)
{
    int num;
    char op;
    vector<string> exp;
    stringstream ss(expression);

    while (ss >> num && ss >> op)
    {
        exp.push_back(to_string(num));
        exp.push_back(string(1, op));
    }
    exp.push_back(to_string(num));

    DFS(0, "", "+-*", exp);

    return answer;
}