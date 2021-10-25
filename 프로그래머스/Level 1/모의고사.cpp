#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers)
{
    vector<int> answer;
    vector<int> hit(3, 0);
    vector<int> rnd1 = { 1, 2, 3, 4, 5 };
    vector<int> rnd2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> rnd3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    int max = -1;

    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == rnd1[i % 5]) hit[0]++;
        if (answers[i] == rnd2[i % 8]) hit[1]++;
        if (answers[i] == rnd3[i % 10]) hit[2]++;
    }

    for (int i = 0; i < 3; i++)
        if (max < hit[i])
            max = hit[i];

    for (int i = 0; i < 3; i++)
        if (max == hit[i])
            answer.push_back(i + 1);

    return answer;
}