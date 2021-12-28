#include <string>
#include <vector>
#include <regex>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.second > b.second;
}

vector<int> solution(string s)
{
    vector<int> answer;
    unordered_map<int, int> m;
    int num;
    s = regex_replace(s, regex("[{}]"), "");
    s = regex_replace(s, regex(","), " ");
    stringstream ss(s);
    while (ss >> num)
        m[num]++;

    vector<pair<int, int>> v(m.begin(), m.end());

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++)
        answer.push_back(v[i].first);

    return answer;
}