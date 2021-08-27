#include <iostream>

using namespace std;

string sorting(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		char tmp;
		for (int j = i; j < str.size(); j++)
		{
			if (str[i] > str[j])
			{
				tmp = str[i];
				str[i] = str[j];
				str[j] = tmp;
			}
		}
	}
	return str;
}

int main()
{
	string str1, str2, result;
	
	cin >> str1 >> str2;

	str1 = sorting(str1);
	str2 = sorting(str2);

	result = str1 == str2 ? "YES" : "NO";

	cout << result;
}

//void cal_Alphabet(string str, char *arr)
//{
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (str[i] >= 'A' && str[i] <= 'Z')
//			arr[str[i] - 'A']++;
//		else if (str[i] >= 'a' && str[i] <= 'z')
//			arr[str[i] - 'a' + 26]++;
//	}
//}
//
//int main()
//{
//	string str1, str2;
//
//	char a[52], b[52];
//
//	cin >> str1 >> str2;
//
//	cal_Alphabet(str1, a);
//	cal_Alphabet(str2, b);
//
//	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//	{
//		if (a[i] != b[i]) 
//		{
//			cout << "NO";  
//			return 0;
//		}
//	}
//
//	cout << "YES";
//	return 0;
//}
