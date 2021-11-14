#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int pos;

bool cmp(const string& a, const string& b)
{
    if (a[pos] == b[pos])
        return (a.compare(b) <= 0);
    else
        return a[pos] < b[pos];
}

vector<string> solution(vector<string> strings, int n)
{
    pos = n;
    sort(strings.begin(), strings.end(), cmp);
    return strings;
}