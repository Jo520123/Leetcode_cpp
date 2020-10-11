#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		
		int l = nums.size();
		unordered_map<int, int> table;

		table.insert({ 0,-1 });
		int total = 0;
		int ans = 0;

		for (int &i : nums)
		{
			if (i == 0)
			{
				i = -1;
			}
		}

		for (int i = 0; i<l; i++)
		{

			total += nums[i];

			if (table.count(total))
			{

				ans = max(i - table[total], ans);

			}
			else
			{
				table.insert({total, i});

			}

		}

		return ans;

	}
};

int main()
{

	Solution *x = new Solution();

	vector<int> Input1 = { 0, 1 };

	cout << x->findMaxLength(Input1);
	cin.get();

	//Input: [0, 1] 
	//Output : 2


	vector<int> Input2 = { 0, 1 };

	cout << x->findMaxLength(Input2);
	cin.get();
	//Input : [0, 1, 0]
	//Output : 2

	return 0;

}
