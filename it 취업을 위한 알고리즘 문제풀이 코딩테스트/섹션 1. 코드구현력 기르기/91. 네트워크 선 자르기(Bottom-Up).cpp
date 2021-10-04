#include <iostream>

using namespace std;


int main()
{
	int line[46];
	int n; 

	cin >> n;

	line[1] = 1;
	line[2] = 2;

	for (int i = 3; i <= n; i++)
		line[i] = line[i - 1] + line[i - 2];

	cout << line[n];
}
