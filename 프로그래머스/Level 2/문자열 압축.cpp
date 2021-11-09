#include <string>

using namespace std;

int solution(string s)
{
    int answer = s.size();

    for (int i = 1; i <= s.size() / 2; i++)
    {
        int cnt = 1;
        string slice = s.substr(0, i);
        string res = "";

        for (int j = i; j < s.size(); j += i)
        {
            if (slice.compare(s.substr(j, i)) == 0)
                cnt++;
            else
            {
                if (cnt != 1)
                    res += to_string(cnt);
                res += slice;
                slice = s.substr(j, i);
                cnt = 1;
            }

        }

        if (cnt != 1)
            res += to_string(cnt);

        res += slice;
        answer = res.size() < answer ? res.size() : answer;
    }

    return answer;
}