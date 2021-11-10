#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record)
{
    vector<string> answer;
    map<string, string> m;

    for (int i = 0; i < record.size(); i++)
    {
        stringstream ss(record[i]);
        string state, id, name;

        ss >> state;

        if (!state.compare("Leave")) continue;

        ss >> id, ss >> name;
        m[id] = name;
    }


    for (int i = 0; i < record.size(); i++)
    {
        stringstream ss(record[i]);
        string state, id, name, res;

        ss >> state, ss >> id;
        if (!state.compare("Change")) continue;

        res = m[id] + "���� ";
        if (!state.compare("Enter"))
            res += "���Խ��ϴ�.";
        else
            res += "�������ϴ�.";
        answer.push_back(res);
    }

    return answer;
}