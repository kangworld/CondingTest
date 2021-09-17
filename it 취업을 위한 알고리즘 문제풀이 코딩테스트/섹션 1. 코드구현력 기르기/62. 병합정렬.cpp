#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[101];
int tmp[101];

void divide(int lt, int rt)
{
	int mid;

	if (lt < rt)
	{
		mid = (lt + rt) / 2;
		divide(lt, mid);
		divide(mid + 1, rt);

		int p1 = lt;
		int p2 = mid + 1;
		int p3 = lt;
		while (p1 <= mid && p2 <= rt)
		{
			if (arr[p1] < arr[p2]) tmp[p3++] = arr[p1++];
			else tmp[p3++] = arr[p2++];
		}

		while (p1 <= mid) tmp[p3++] = arr[p1++];
		while (p2 <= rt) tmp[p3++] = arr[p2++];

		for (int i = lt; i <= rt; i++)
			arr[i] = tmp[i];
	}
}

int main()
{
	int n; 

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	divide(1, n);

	for (int i = 1; i <= n; i++)
		cout << tmp[i] << " ";
}