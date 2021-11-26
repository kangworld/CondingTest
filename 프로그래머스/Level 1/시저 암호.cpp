#include <string>

using namespace std;

string solution(string s, int n)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (islower(s[i]))
		{
			if (!islower(s[i] += n))
				s[i] -= 26;
		}
		else if (isupper(s[i]))
		{
			if (!isupper(s[i] += n))
				s[i] -= 26;
		}
	}

	return s;
}