#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

class Solution 
{
	public:
		vector<int> topKFrequent(vector<int>& nums, int k)
		{

			map<int, int> table;
			priority_queue<pair<int, int>> q;
			vector<int> ans;

			for (int i : nums)
			{

				table[i] += 1;

			}

			
			for (auto i : table)
			{
				q.push({ i.second, i.first });

			}

			
			for (int i = 0; i < k; i++)
			{

				ans.push_back(q.top().second);
				q.pop();

			}


			return ans;

		}

};

int main()
{
	Solution x;

	vector<int> t = {1,1,1,2,2,3};//return[1, 2].

	int k = 2;

	vector<int> A;
	A = x.topKFrequent(t, k);

	cout << "[ ";
	for (int i : A)	
	{
		cout << i << " ";
	}
	cout << "]";
	cin.get(); 


	vector<int> t1 = { 1,2 }; //return[1, 2].
	int k1 = 2;

	vector<int> A1;
	A1 = x.topKFrequent(t1, k1);

	cout << "[ ";
	for (int i : A1)
	{
		cout << i << " ";
	}
	cout << "]";
	cin.get(); 

}
