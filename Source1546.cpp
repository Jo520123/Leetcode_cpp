#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
	int maxNonOverlapping(vector<int>& nums, int target) {

		int sum = 0;
		int c = 0;

		unordered_set<int> uos;
		uos = {0};


		for (auto& x : nums)
		{
			sum += x;

			if (uos.count(sum - target) == 1)
			{
				sum = 0;
				uos = { 0 };
				c += 1;

			}
			else
			{
				
				uos.insert(sum);

			}

		}

		return c;

	}
};


int main()
{

	Solution *x = new Solution();

	vector<int> nums1 = { 1, 1, 1, 1, 1 };
	int target1 = 2;

	cout << x->maxNonOverlapping(nums1,target1);
	
	//Output : 2

	cin.get();

		
	vector<int> nums2 = { -1, 3, 5, 1, 4, 2, -9 };
	int target2 = 6;

	cout << x->maxNonOverlapping(nums2, target2);
	
	//Output : 2

	cin.get();

	return 0;

}