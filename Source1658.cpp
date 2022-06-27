#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>

using namespace std;

class Solution {
public:
	int minOperations(vector<int>& nums, int x) {

		int goal = accumulate(nums.begin(), nums.end(), 0) - x;
		int l = 0;
		int total= 0;
		bool flag = false;
		int mlen = 0;


		for (int i = 0; i < nums.size(); i++)
		{

			total += nums[i];

			while (l < i && total > goal)
			{

				total -= nums[l];
				l += 1;

			}

			if (goal == total)
			{

				flag = true;
				mlen = max(i - l + 1, mlen);

			}

		}
		
		if (flag == true)
		{

			return nums.size() - mlen;

		}
		else
		{

			return -1;

		}

	}
};


int main()
{

	Solution *x = new Solution();

	vector<int> nums1 = { 1, 1, 4, 2, 3 };
	int x1 = 5;

	cout << x->minOperations(nums1,x1);
	cin.get();
	//Output : 2

	vector<int> nums2 = { 5, 6, 7, 8, 9 };
	int x2 = 4;

	cout << x->minOperations(nums2, x2);
	cin.get();
	//Output : -1

	vector<int> nums3 = { 3, 2, 20, 1, 1, 3 };
	int x3 = 10;

	cout << x->minOperations(nums3, x3);
	cin.get();
	//Output : 5

}