#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;



class Solution 
{
	public:
		bool isReflected(vector<pair<int, int>> & points)
		{
			set<pair<int, int >> store;

			int Min = INT_MAX;
			int Max = INT_MIN;
			int sum;
			

			for (auto x : points)
			{
				Max = max(x.first, Max);
				Min = min(x.first, Min);

				store.insert(x);
			}


			sum = Max + Min;


			for (auto x : points)
			{
				if (store.count(make_pair(sum - x.first, x.second)) == 0)
				{
					cout << "False"<<"\n";
					return false;
				}


			}

			cout << "True"<< "\n";
			return true;

		}

};

int main() 
{


	vector<pair<int, int>> p;
	vector<pair<int, int>> p1;

	int arr[] = { 1, -1 };
	int arr1[] = { 1, 1 };
	int arr11[] = { 1, -1 };
	int arr111[] = { 1, -1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < n; i++) {
		p.push_back(make_pair(arr[i], arr1[i]));
		p1.push_back(make_pair(arr11[i], arr111[i]));
	}


	for (int i= 0 ; i<n ; i++)
	{
		cout << p[i].first <<" "<< p[i].second << "\n";

	}

	for (int i = 0; i < n; i++)
	{
		cout << p1[i].first << " " << p1[i].second << "\n";

	}

	cin.get();

	Solution *x = new Solution();

	x-> isReflected(p);
	//Given points = [[1, 1], [-1, 1]], return true.
	x-> isReflected(p1);
	//Given points = [[1, 1], [-1, -1]], return false.

	cin.get();

}