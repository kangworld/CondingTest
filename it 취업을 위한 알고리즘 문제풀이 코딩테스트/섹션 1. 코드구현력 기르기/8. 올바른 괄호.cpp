#include <iostream>

using namespace std;
int main()
{
	string str;
	int diff = 0;

	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(') 
			diff++;
		else if (str[i] == ')')
		{
			diff--;
			if (diff < 0)
			{
				cout << "NO";
				return 0;
			}

			/* 더 좋은 코드
			*
			if (diff < 0)
			{
				break;
			} 
			*/
		}
	}

	if (diff == 0) cout << "YES";
	else cout << "NO";


}