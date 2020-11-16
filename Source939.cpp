#include<iostream>
#include<vector>
#include<set>
#include<stdlib.h>
#include<algorithm>
using namespace std;


class Solution {
public:
	int minAreaRect(vector<vector<int>>& points) {

		int ans = INT_MAX;
		const int l = points.size();
		set<pair<int, int>> unique_vertex;

		for (auto x: points) 
		{
			unique_vertex.insert(make_pair(x[0], x[1]));


		}

		for (int i = 0; i < l; i++)
		{
			for (int j=i+1; j < l; j++)
			{

				auto vertex1 = points[i];
				auto vertex2 = points[j];

				if (vertex1[0] == vertex2[0] || vertex1[1] == vertex2[1])
				{
					continue;
				}

				pair<int, int> vertex3 = { vertex2[0],vertex1[1]};
				pair<int, int> vertex4 = { vertex1[0],vertex2[1]};


				if (unique_vertex.count(vertex3) && unique_vertex.count(vertex4))
				{
					ans = min(ans, abs(vertex2[0] - vertex1[0])*abs(vertex2[1] - vertex1[1]));
				}

			}
		}

		if (ans != INT_MAX)
		{
			return ans;
		}
		else
		{
			return 0;
		}

	}
};


int main() 
{
	Solution *x = new Solution();
	vector<vector<int>> points1 = { {1,1}, {1,3}, {3,1}, {3,3}, {2,2} };
	vector<vector<int>> points2 = { {1,1}, {1,3}, {3,1}, {3,3}, {4,1}, {4,3}};

	cout << x-> minAreaRect(points1);	
	//Output: 4
	cin.get();

	cout << x-> minAreaRect(points2);
	//Output : 2

	cin.get();

	return 0;

}