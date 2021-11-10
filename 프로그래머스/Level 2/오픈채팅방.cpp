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

        res = m[id] + "님이 ";
        if (!state.compare("Enter"))
            res += "들어왔습니다.";
        else
            res += "나갔습니다.";
        answer.push_back(res);
    }

    return answer;
}