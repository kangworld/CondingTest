#include <iostream>

using namespace std;

int main()
{
	//freopen("input.txt", "rt", stdin);
	int n;

	cin >> n;

	int* a = new int[n];
	int* b = new int[n];

	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	for (int i = 0; i < n; i++)
	{
		if (a[i] == b[i]) cout << "D" << endl;
		else if (a[i] == 1 && b[i] == 3) cout << "A" << endl;
		else if (a[i] == 2 && b[i] == 1) cout << "A" << endl;
		else if (a[i] == 3 && b[i] == 2) cout << "A" << endl;
		else cout << "B" << endl;
	}
}