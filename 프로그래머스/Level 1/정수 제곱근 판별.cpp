#include <math.h>

using namespace std;

long long solution(long long n)
{
    int a = sqrt(n);

    if (pow(a, 2) == n)
        return pow(a + 1, 2);
    else
        return -1;
}