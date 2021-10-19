#include <string>
#include <vector>

using namespace std;

string solution(string new_id)
{
    string answer = "";
    string tmp = "";
    bool preDot = false;

    //step1
    for (int i = 0; i < new_id.size(); i++)
        if (isupper(new_id[i]))
            new_id[i] = tolower(new_id[i]);

    //step2
    for (int i = 0; i < new_id.size(); i++)
    {
        if ((new_id[i] >= 'a' && new_id[i] <= 'z') ||
            (new_id[i] >= '0' && new_id[i] <= '9') ||
            new_id[i] == '-' ||
            new_id[i] == '_' ||
            new_id[i] == '.') tmp += new_id[i];
    }
    new_id = tmp;
    tmp.clear();

    //step3
    for (int i = 0; i < new_id.size(); i++)
    {
        if (new_id[i] == '.' && !preDot)
        {
            preDot = true;
            tmp += new_id[i];
        }
        else if (new_id[i] != '.')
        {
            preDot = false;
            tmp += new_id[i];
        }
    }
    new_id = tmp;
    tmp.clear();

    //step4
    if (new_id.front() == '.')
        new_id.erase(new_id.begin());
    if (new_id.back() == '.')
        new_id.pop_back();

    //step5
    if (new_id.empty())
        new_id += 'a';

    //step6
    if (new_id.size() >= 16)
    {
        new_id.erase(new_id.begin() + 15, new_id.end());
        if (new_id.back() == '.')
            new_id.erase(new_id.end() - 1);
    }

    //step7
    if (new_id.size() <= 2)
        while (new_id.size() != 3)
            new_id += new_id.back();

    answer = new_id;

    return answer;
}