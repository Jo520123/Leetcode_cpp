#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;


class Solution {
public:
	int findLHS(vector<int>& nums) {
		map<int, int> table;
		int ans = 0;

		for (int &i : nums)
		{
			table[i] += 1;
		}

		for (auto i : table)
		{
			if (table.count(i.first+1))
			{

				ans = max(table[i.first] + table[i.first + 1], ans);

			}


		}

		return ans;

	}
};

int main() {

	Solution *x = new Solution();

	vector<int> nums1 = { 1, 3, 2, 2, 5, 2, 3, 7 };
	cout << x->findLHS(nums1);
	//Output: 5
	cin.get();

	vector<int> nums2 = { 1, 2, 3, 4 };
	cout << x->findLHS(nums2);
	//Output : 2
	cin.get();

	vector<int> nums3 = { 1, 1, 1, 1 };
	cout << x->findLHS(nums3);
	//Output : 0
	cin.get();


	return 0;

}