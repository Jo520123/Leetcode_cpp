#include<iostream>
#include<vector>
using namespace std;



class Solution {
public:
	vector<int> findErrorNums(vector<int>& nums) {

		int l = nums.size();
		vector<int> ans(2, 0);
		vector<int> table(l, 0);


		for (int x : nums)
		{
			table[x - 1] += 1;
		}

		for (int i=0 ; i < l; i++)
		{

			if (ans[0] != 0 && ans[1] != 0)
			{
				return ans;
			}

			if (table[i] == 0)
			{
				ans[1] = i + 1;

			}
			else if (table[i] == 2)
			{

				ans[0] = i + 1;


			}

		}

		return ans;

	}
};

int main()
{

	Solution *x = new Solution();

	vector<int> nums = { 1, 2, 2, 4 };
	
	for (int i : x->findErrorNums(nums))
	{

		cout << i << " ";
	}

	cin.get();
	//Output : [2, 3]

	return 0;

}

