#include <iostream>

using namespace std;
int main(void)
{
	int a, b, sum = 0;
	
	cin>>a>>b;

	for(int i = a; i < b; i++)
	{
		sum += i;
		cout << i << " " << "+ ";
	}
	sum += b;
	cout << b << " = " << sum;
	
	return 0;
}
