#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> m;

void DFS(int now, int pos, string comb, string order, int target)
{
    if (now == target)
    {
        m[comb]++;
        return;
    }

    for (int i = pos; i < order.size(); i++)
        DFS(now + 1, i + 1, comb + order[i], order, target);
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;

    for (int i = 0; i < orders.size(); i++)
        sort(orders[i].begin(), orders[i].end());

    for (int i = 0; i < course[i]; i++)
    {
        for (int j = 0; j < orders.size(); j++)
            DFS(0, 0, "", orders[j], course[i]);

        int maxCnt = 0;
        for (auto iter : m)
            maxCnt = iter.second > maxCnt ? iter.second : maxCnt;

        for (auto iter : m)
            if (iter.second >= 2 && maxCnt == iter.second)
                answer.push_back(iter.first);
        m.clear();
    }


    sort(answer.begin(), answer.end());
    return answer;
}