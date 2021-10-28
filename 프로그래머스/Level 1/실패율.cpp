#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(const pair<double, int> p1, const pair<double, int> p2)
{
	if (p1.first != p2.first)
		return p1.first > p2.first;
	else
		return p1.second < p2.second;
}

vector<int> solution(int N, vector<int> stages) 
{
	vector<int> answer;
	vector<pair<double, int>> pr;

	for (int i = 1; i <= N; i++)
	{
		int clear = 0, fail = 0;
		for (int j = 0; j < stages.size(); j++)
		{
			if (i <= stages[j])
			{
				clear++;
				if (i == stages[j])
					fail++;
			}
		}

		if (clear == 0)
			pr.push_back(make_pair(0, i));
		else
			pr.push_back(make_pair((double)fail / clear, i));
	}

	sort(pr.begin(), pr.end(), cmp);

	for (int i = 0; i < N; i++)
		answer.push_back(pr[i].second);

	return answer;
}