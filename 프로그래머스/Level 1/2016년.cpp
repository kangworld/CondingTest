#include <string>
#include <vector>

using namespace std;

string solution(int a, int b)
{
    vector<int> m = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    vector<string> week = { "THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED" };

    int days = 0;

    for (int i = 0; i < a; i++)
        days += m[i];
    days += b;

    return week[days % 7];
}