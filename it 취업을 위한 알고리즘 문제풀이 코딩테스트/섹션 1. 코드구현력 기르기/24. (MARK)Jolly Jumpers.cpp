#include <iostream>
#include <vector>

using namespace std;

//int main()
//{
//	/*freopen("input.txt", "rt", stdin);*/
//	
//	int n, idx;
//	
//	cin >> n;
//
//	vector<int> vi(n);
//	vector<bool> vb(n);
//
//	for (int i = 0; i < n; i++)
//		cin >> vi[i];
//
//	for (int i = 1; i < n; i++)
//	{
//		idx = vi[i] - vi[i - 1];
//		idx = idx > 0 ? idx : -idx;
//
//		if (idx > n - 1 || idx == 0)
//		{
//			cout << "NO";
//			return 0;
//		}
//
//		vb[idx] = !vb[idx];
//	}
//
//	for (int i = 1; i < n; i++)
//	{
//		if (vb[i] == false)
//		{
//			cout << "NO";
//			return 0;
//		}
//	}
//
//	cout << "YES";
//	return 0;
//}

//강의보고 참조한 코드
int main()
{
	/*freopen("input.txt", "rt", stdin);*/

	int n, pos;

	cin >> n;

	vector<int> numV(n);
	vector<bool> checkV(n);

	for (int i = 0; i < n; i++)
		cin >> numV[i];

	for (int i = 1; i < n; i++)
	{
		pos = numV[i] - numV[i - 1];
		pos = pos > 0 ? pos : -pos;

		if (pos > 0 && pos < n && checkV[pos] == false) checkV[pos] = true;
		else { cout << "NO"; return 0; }
	}

	cout << "YES";
	return 0;
}
