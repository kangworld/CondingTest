#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

pair<int, int> getXYPos(int num)
{
    if(num == 0)
        return make_pair(3,1);
    
    int posY = (num - 1) / 3;
    int posX = (num - 1) % 3;
    
    return make_pair(posY, posX);
}

string solution(vector<int> numbers, string hand)
{
    string answer = "";
    int rtPos = 12, ltPos = 10, distL, distR;
    pair<int, int> nowXY, ltXY, rtXY;

    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
        {
            answer += "L";
            ltPos = numbers[i];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
        {
            answer += "R";
            rtPos = numbers[i];
        }
        else
        {
            nowXY = getXYPos(numbers[i]);
            ltXY = getXYPos(ltPos);
            rtXY = getXYPos(rtPos);

            distL = abs(nowXY.first - ltXY.first) + abs(nowXY.second - ltXY.second);
            distR = abs(nowXY.first - rtXY.first) + abs(nowXY.second - rtXY.second);

            if (distR < distL)
            {
                answer += "R";
                rtPos = numbers[i];
            }
            else if (distR > distL)
            {
                answer += "L";
                ltPos = numbers[i];
            }
            else
            {

                if (hand == "right")
                {
                    answer += "R";
                    rtPos = numbers[i];
                }
                else
                {
                    answer += "L";
                    ltPos = numbers[i];
                }
            }
        }
    }
    return answer;
}