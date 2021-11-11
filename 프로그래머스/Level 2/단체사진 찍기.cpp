#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int answer, n;
vector<int> alphaIndex(26);
vector<int> order(8);
vector<bool> visited(8);
vector<string> dataset;

void DFS(int now)
{
    if (now == 8)
    {
        int pos1, pos2, cnt, dist;
        char op;
        for (string s : dataset)
        {
            pos1 = alphaIndex[s[0] - 'A'];
            pos2 = alphaIndex[s[2] - 'A'];
            op = s[3];
            cnt = s[4] - '0';

            dist = abs(order[pos1] - order[pos2]) - 1;

            //조건을 만족하는지
            if (op == '=' && dist == cnt ||
                op == '>' && dist > cnt ||
                op == '<' && dist < cnt)
                continue;
            else
                return;
        }
        answer++;
        return;
    }

    for (int i = 0; i < 8; i++)
    {
        if (visited[i])
            continue;

        visited[i] = true;
        order[now] = i;
        DFS(now + 1);
        visited[i] = false;
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int _n, vector<string> data)
{
    answer = 0;
    n = _n;
    dataset = data;
    string names = "ACFJMNRT";
    for (int i = 0; i < names.size(); i++)
        alphaIndex[names[i] - 'A'] = i;

    DFS(0);
    return answer;
}