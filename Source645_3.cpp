#include<iostream>
#include<vector>
using namespace std;



class Solution {
public:
	vector<int> findErrorNums(vector<int>& nums) {

		vector<int> ans(2, 0);

		for (int i = 0; i < nums.size(); i++)
		{
			while (nums[i] != nums[nums[i] - 1])
			{
				swap(nums[i] , nums[nums[i] - 1]);
			}

		}

		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != i + 1)
			{
				ans[0] = nums[i];
				ans[1] = i + 1;

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

	return 0;

}