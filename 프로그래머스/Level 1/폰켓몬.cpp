#include <vector>
using namespace std;

int solution(vector<int> nums)
{
    vector<bool> ch(200001, false);
    vector<int> pkm;

    for (int i = 0; i < nums.size(); i++)
    {
        if (ch[nums[i]] == false)
        {
            pkm.push_back(nums[i]);
            ch[nums[i]] = true;
        }
    }

    if (pkm.size() < nums.size() / 2)
        return pkm.size();

    return nums.size() / 2;
}