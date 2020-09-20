#include <iostream>
#include<unordered_map>
#include<vector>

using namespace std;

class solution {
public:
	unordered_map<int, int> store;

	void add(int number)
	{
		store[number] += 1;
	}

	bool find(int value)
	{
		for (auto x : store)
		{
			int ans = value - x.first;
			if (ans != x.first && store.count(ans) || (ans == x.first && x.second > 1))
			{

				cout << "true";
				return true;

			}

		}
		cout << "false";
		return false;
	
	}

};

int main()
{

	solution x;

	x.add(1);
	x.add(3);
	x.add(5);

	x.find(4);
	cin.get();
	//#find(4) -> true
	x.find(7);
	cin.get();
	//#find(7) -> false

}