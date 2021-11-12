#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) 
{
    vector<string> answer;

    for (int i = 0; i < n; i++)
    {
        int sum = arr1[i] | arr2[i];
        string code;
        for (int i = 0; i < n; i++)
        {
            if (sum % 2 == 1) code += "#";
            else code += " ";

            sum = sum / 2;
        }
        reverse(code.begin(), code.end());
        answer.push_back(code);
    }

    return answer;
}