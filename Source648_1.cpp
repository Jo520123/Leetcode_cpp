#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;


class Solution {
public:
	string replaceWords(vector<string>& dictionary, string sentence) {
		vector<vector<string>> table(26);
		string val;
		string ans;
		
		
		for (string x : dictionary)
		{
			table[x[0] - 'a'].push_back(x);
		}

		istringstream iss(sentence);


		while (iss >> val)
		{
			
			for (string x : table[val[0]-'a']) 
			{
			
				if (x == val.substr(0, x.size()))
				{

					val = x;

					break;

				}
			
			
			}

			ans += val + ' ';


		}

		ans.pop_back();

		return ans;

	}
};




int main()
{	
	Solution *x = new Solution();

	vector<string> dictionary1 = { "cat", "bat", "rat" };
	string sentence1 = "the cattle was rattled by the battery";
	//Output: "the cat was rat by the bat"
	cout << x->replaceWords(dictionary1, sentence1) << endl;



	vector<string> dictionary2 = { "a", "b", "c" };
	string sentence2 = "aadsfasf absbs bbab cadsfafs";
	cout << x->replaceWords(dictionary2, sentence2) << endl;
	//Output: "a a b c"


	vector<string> dictionary3 = { "a", "aa", "aaa", "aaaa" };
	string sentence3 = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa";
	cout << x->replaceWords(dictionary3, sentence3) << endl;
	//Output: "a a a a a a a a bbb baba a"


	vector<string> dictionary4 = { "catt", "cat", "bat", "rat" };
	string sentence4 = "the cattle was rattled by the battery";
	cout << x->replaceWords(dictionary4, sentence4) << endl;
	//Output: "the cat was rat by the bat"


	vector<string> dictionary5 = { "ac", "ab" };
	string sentence5 = "it is abnormal that this solution is accepted";
	cout << x->replaceWords(dictionary5, sentence5) << endl;
	//Output : "it is ab that this solution is ac"
	cin.get();
		

	return 0;

}