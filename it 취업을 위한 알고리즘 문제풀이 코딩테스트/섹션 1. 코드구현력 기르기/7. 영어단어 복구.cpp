#include <iostream>
#include <string>

using namespace std;
int main()
{
	string str;
	int diff = 'a' - 'A';

	getline(cin, str);

	for (int i = 0; i < str.size(); i++) 
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			cout << str[i];
		else if (str[i] >= 'A' && str[i] <= 'Z')
			cout << (char)(str[i] + diff);
	}
}