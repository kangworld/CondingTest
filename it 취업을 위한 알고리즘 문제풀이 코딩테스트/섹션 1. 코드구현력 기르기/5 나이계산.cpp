#include <iostream>

using namespace std;
int main()
{
    string id;
    int age;
    char gender;

    cin >> id;

    if (id[7] == '1' || id[7] == '2') age = 1900 + (id[0] - '0') * 10 + (id[1] - '0');
    else if (id[7] == '3' || id[7] == '4') age = 2000 + (id[0] - '0') * 10 + (id[1] - '0');

    if (id[7] == '1' || id[7] == '3') gender = 'M';
    else if (id[7] == '2' || id[7] == '4') gender = 'W';

    cout << 2019 - age + 1 << " " << gender;

    return 0;
}