#include <iostream>

using namespace std;
int main()
{
    int n, age, min = 100, max = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> age;

        if (age < min) min = age;
        if (age > max) max = age;
    }

    cout << max - min;

    return 0;
}