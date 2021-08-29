#include <iostream>

using namespace std;

int main()
{
	//freopen("input.txt", "rt", stdin);
	
	int a[10], b[10], lastWinA = 0, lastWinB = 0, scoreA = 0, scoreB = 0;
	
	for (int i = 0; i < 10; i++)
		cin >> a[i];
	for (int i = 0; i < 10; i++)
		cin >> b[i];

	for (int i = 0; i < 10; i++)
	{
		if (a[i] == b[i]) { scoreA++; scoreB++; }
		else if (a[i] > b[i]) { scoreA += 3; lastWinA = i; }
		else { scoreB += 3; lastWinB = i; }
	}

	cout << scoreA << " " << scoreB << endl;
	
	if (scoreA > scoreB) cout << "A";
	else if (scoreA < scoreB) cout << "B";
	else
	{
		if (lastWinA > lastWinB) cout << "A";
		else if (lastWinA < lastWinB) cout << "B";
		else cout << "D";
	}
}

// 강의 참고 코드 lastWinA, lastWinB를 하나로 변경함
//int main()
//{
//	//freopen("input.txt", "rt", stdin);
//
//	int a[10], b[10], lastWin = 0, scoreA = 0, scoreB = 0;
//
//	for (int i = 0; i < 10; i++)
//		cin >> a[i];
//	for (int i = 0; i < 10; i++)
//		cin >> b[i];
//
//	for (int i = 0; i < 10; i++)
//	{
//		if (a[i] == b[i]) { scoreA++; scoreB++; }
//		else if (a[i] > b[i]) { scoreA += 3; lastWin = 1; }
//		else { scoreB += 3; lastWin = 2; }
//	}
//
//	cout << scoreA << " " << scoreB << endl;
//
//	if (scoreA > scoreB) cout << "A";
//	else if (scoreA < scoreB) cout << "B";
//	else
//	{
//		if (lastWin == 1) cout << "A";
//		else if (lastWin == 2) cout << "B";
//		else cout << "D";
//	}
//}