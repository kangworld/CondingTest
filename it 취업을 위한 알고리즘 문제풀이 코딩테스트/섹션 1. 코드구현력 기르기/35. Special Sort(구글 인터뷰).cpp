#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;

	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++) 
		cin >> v[i];

	/*Bubble Sort Begin*/
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n -i - 1; j++)
		{
			if (v[j] > 0 && v[j+1] < 0)
			{
				int temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
	/*Bubble Sort End*/

	for (int i = 0; i < n; i++)
		cout << v[i] << " ";
}