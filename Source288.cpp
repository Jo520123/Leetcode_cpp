#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<string>
using namespace std;

class solution {
public:
	unordered_map<string, unordered_set<string>> table;


	void ValidWordAbbr(vector<string> &dictionary)
	{
		for (string & x : dictionary)
		{
			string abr = abbreviation(x);
			table[abr].emplace(x);

		}

	}

	bool isUnique(string word)
	{
		const string abr = abbreviation(word);
		if (table[abr].empty() || (table[abr].count(word) == 1 && table[abr].size()==1))
		{
			cout << "True\n";
			return true;
		}

		cout << "False\n";
		return false;

		

	}
		
	string abbreviation(string & x)
	{
	
		if (x.length() < 2)
		{
			return x;
		}
	
		return x.front() + to_string(x.length()-2) + x.back();
	
	}

};

int main() 
{
	vector<string> d = { "deer", "door", "cake", "card" };
	solution v;
	v.ValidWordAbbr(d);

	string x1 = "dear";
	string x2 = "cart";
	string x3 = "cane";
	string x4 = "make";

	v.isUnique(x1);  //false
	v.isUnique(x2);  //true
	v.isUnique(x3);  //false
	v.isUnique(x4);  //true

	cin.get();


	return 0;

}