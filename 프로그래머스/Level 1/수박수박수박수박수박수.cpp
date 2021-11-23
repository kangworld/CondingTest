#include <string>

using namespace std;

string solution(int n)
{
	string answer;

	for (int i = 0; i < n; i++)
		if (i % 2) answer += "¹Ú";
		else answer += "¼ö";

	return answer;
}