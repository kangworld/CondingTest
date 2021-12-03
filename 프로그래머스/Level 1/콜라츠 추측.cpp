using namespace std;

int solution(int n)
{
    int answer = 0;
    long long num = n;

    while (num != 1)
    {
        if (answer >= 500) return -1;
        num = num & 1 ? (num * 3) + 1 : num / 2;
        answer++;
    }

    return answer;
}