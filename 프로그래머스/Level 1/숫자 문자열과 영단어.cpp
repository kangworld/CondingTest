#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = 0;
    string alpha = "";

    vector<string> words = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            answer = answer * 10 + (s[i] - '0');
        else
        {
            alpha += s[i];

            if (alpha.size() >= 3)
                for (int j = 0; j < words.size(); j++)
                {
                    if (alpha.compare(words[j]) == 0)
                    {
                        answer = answer * 10 + j;
                        alpha.clear();
                    }
                }
        }
    }

    return answer;
}