#include<iostream>
#include<stdlib.h>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		const int l = T.size();
		vector<int> ndays(l,0);
		stack<int> s;

		for (int i=0; i < l; i++)
		{
			int cur = T[i];

			while (!s.empty())

			{
				if (cur > T[s.top()])
				{
					ndays[s.top()] = i - s.top();
					s.pop();
				}
				else
				{
					break;
				}

			}

			s.push(i);

		}
		return ndays;

	}
};

int main()
{

	vector<int> T = { 73, 74, 75, 71, 69, 72, 76, 73 };

	Solution x;

	vector<int> y;
	
	y = x.dailyTemperatures(T);

	for (int i : y)
	{

		cout << i;

	}
	cin.get();
	
	return 0;

}
