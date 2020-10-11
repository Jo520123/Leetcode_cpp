#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	//TreeNode() : val(0), left(nullptr), right(nullptr) {}
	//TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	//TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	vector<int> total;
	map<int, int> table;
	int h_freq = 0;


	int addn(TreeNode *root)
	{
		if (!root)
		{
			return 0;
		}

		int root_l = addn(root->left);
		int root_r = addn(root->right);
		int sum = root-> val + root_l + root_r;

		table[sum] += 1;
		h_freq = max(h_freq, table[sum]);

		
		return sum;

	}

	vector<int> findFrequentTreeSum(TreeNode *root) {
		
		addn(root);
		vector<int> ans;

		for (auto i : table)
		{
			if (i.second == h_freq)
			{
				ans.push_back(i.first);
			}

		}

		return ans;

	}
};

int main()
{

	struct TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(2);
	root->right = new TreeNode(-3);

	Solution *x = new Solution();

	for (int i : x->findFrequentTreeSum(root))
	{
		cout << i << endl;

	}
	cin.get();
	//return[2, -3, 4]



	struct TreeNode *root1 = new TreeNode(5);
	root1->left = new TreeNode(2);
	root1->right = new TreeNode(-5);

	Solution *x1 = new Solution();

	for (int i : x1->findFrequentTreeSum(root1))
	{
		cout << i << endl;

	}
	cin.get();

	//return[2]

	return 0;
}