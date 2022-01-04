#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string& a, const string& b)
{
    return a < b;
}

bool solution(vector<string> phone_book)
{
    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size() - 1; i++)
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size()))
            return false;

    return true;
}