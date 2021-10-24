#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer, tmp;
    int s, d, k; //start dest k

    for (int i = 0; i < commands.size(); i++)
    {
        s = commands[i][0] - 1;
        d = commands[i][1];
        k = commands[i][2] - 1;

        for (int j = s; j < d; j++)
            tmp.push_back(array[j]);

        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[k]);
        tmp.clear();
    }

    return answer;
}