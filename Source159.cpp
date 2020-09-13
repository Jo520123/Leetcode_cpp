#include<iostream>
#include<stdlib.h>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class solution {
public:
	int lengthOfLongestSubstringTwoDistinct(string s)
	{
		int left=0, max_len=0;
		unordered_map<char, int> store;
		

		for (int i = 0; i < s.size(); i++)
		{
		
			store[s[i]] += 1;
			
			
			while (store.size() > 2)
			{
				store[s[left]] -= 1;
				
				if (store[s[left]] == 0)
				{
					store.erase(s[left]);
				}

				left += 1;

			}

			max_len = max(max_len, i - left + 1);

		}

		return max_len;
	}

};


int main() 
{
	solution x;

	char string1[] = "eceba";
	int y1;
	//Input: "eceba"
	//Output : 3 "ece"
	
	y1 = x.lengthOfLongestSubstringTwoDistinct(string1);
	cout << y1;
	cin.get();


	char string2[] = "ccaabbb";
	int y2;
	//Input : "ccaabbb"
	//Output : 5 "aabbb"
	
	y2 = x.lengthOfLongestSubstringTwoDistinct(string2);
	cout << y2;
	cin.get();


	return 0;
	
}