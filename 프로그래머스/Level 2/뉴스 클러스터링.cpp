#include <string>
#include <algorithm>
#include <map>

#include <iostream>

using namespace std;

int solution(string str1, string str2)
{
    int answer = 0, uni = 0, inter = 0;
    map<string, int> m1, m2;

    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    for (int i = 0; i < str1.size() - 1; i++)
    {
        if (!isalpha(str1[i]) || !isalpha(str1[i + 1])) continue;
        m1[str1.substr(i, 2)]++;
    }
    for (int i = 0; i < str2.size() - 1; i++)
    {
        if (!isalpha(str2[i]) || !isalpha(str2[i + 1])) continue;
        m2[str2.substr(i, 2)]++;
    }

    if (!m1.size() && !m2.size()) return 65536;

    for (auto iter : m1)
        inter += min(iter.second, m2[iter.first]);
    for (auto iter : m1)
    {
        uni += max(iter.second, m2[iter.first]);
        m1[iter.first] = 0, m2[iter.first] = 0;
    }
    for (auto iter : m2)
        uni += max(iter.second, m1[iter.first]);

    return (double)inter / uni * 65536;
}