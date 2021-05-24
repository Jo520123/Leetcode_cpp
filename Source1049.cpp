#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	int lastStoneWeightII(vector<int>& stones) 
	{
		priority_queue <int> que;
		for (int x : stones)
			que.push(x);

		while (que.size() >= 2)
		{	
			int x = que.top();
			que.pop();

			if (!que.empty())
			{
				int y = que.top();
				que.pop();

				if (x != y)
				{
					que.push(abs(x - y));
				}

			}

		}

		if (que.empty())
		{
			return 0;
		}
		else
		{
			return que.top();
		}

	}
};


int main()
{

	Solution x;

	vector<int> stones = { 2, 7, 4, 1, 8, 1 };
	//Output: 1
		
	int ans, ans1;
	ans = x.lastStoneWeightII(stones);

	cout << ans;
	cin.get();

	return 0;

}