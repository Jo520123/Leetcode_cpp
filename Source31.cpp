#include<iostream>
#include<stdlib.h>
#include <vector>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int idx = nums.size() - 1;
		int i = nums.size() - 1;

		while (idx >= 0 && nums[idx] <= nums[idx - 1])
		{
			idx--;
		}

		reverse(nums.begin() + idx, nums.end());

		if (idx > 0)
		{
			while (nums[idx] <= nums[i])
			{
				i--;
			}
			swap(nums[i], nums[idx]);


		}


	}
};

int main() 
{
	vector<int> vect;
	vect.push_back(1);
	vect.push_back(2);
	vect.push_back(3);

	for (int x : vect)
	{
		cout << x << " ";
	}
	cin.get();

	Solution x;
	x.nextPermutation(vect);


	for (int x : vect)
	{
		cout << x << " ";
	}

	cin.get();


	return 0;

}