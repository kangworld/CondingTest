#include <vector>

using namespace std;

int gcd(int a, int b)
{
    int c;

    while (b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

vector<int> solution(int n, int m)
{
    int a = gcd(n, m);
    int b = n * m / a;

    return { a, b };
}