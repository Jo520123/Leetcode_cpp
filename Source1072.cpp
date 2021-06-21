#include<iostream>
#include<stdlib.h>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
		unordered_map<string, int> dic;
		int row = matrix.size();
		int col = matrix[0].size();
		int ans = 0;

		for (int i = 0; i < row; ++i)
		{
			string r;

			for (int j = 0; j < col; ++j)
			{
				if (matrix[i][0] == 1)
				{
					r += to_string(matrix[i][j]);
				}
				else
				{
					r += to_string(!matrix[i][j]);
				}

				
			}
			++dic[r];
			ans = max(dic[r], ans);
		}
		
		return ans;

	}
};

int main() 
{
	Solution *x = new Solution();
	//Input: matrix1 = [[0, 1], [1, 1]]
	//Output : 1
	vector<vector<int>> matrix1 = {{0, 1},{1, 1}};
	std::cout << x-> maxEqualRowsAfterFlips(matrix1);
	cin.get();

	//Input : matrix2 = [[0, 1], [1, 0]]
	//Output : 2
	vector<vector<int>> matrix2 = { {0, 1},{1, 0} };
	cout << x-> maxEqualRowsAfterFlips(matrix2);
	cin.get();

	//Input : matrix3 = [[0, 0, 0], [0, 0, 1], [1, 1, 0]]
	//Output : 2

	vector<vector<int>> matrix3 = { {0, 0, 0},{0, 0, 1},{1, 1, 0} };
	cout << x->maxEqualRowsAfterFlips(matrix3);
	cin.get();

}

