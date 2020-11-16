#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
	int numRabbits(vector<int>& answers) {
		unordered_map<int, int> table;
		int ans=0;

		for (int x : answers)
		{
			table[x] += 1;
		}

		for (auto x : table)
		{
			ans += ((x.first + x.second) / (x.first+1))*(x.first+1);
		
		}

		return ans;

	}
};


int main()
{
	Solution *x = new Solution();
	vector<int> nums = {1,1,2};


	cout << x->numRabbits(nums);

	cin.get();


	return 0;

}