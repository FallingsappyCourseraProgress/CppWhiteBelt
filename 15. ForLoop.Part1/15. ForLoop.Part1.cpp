#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{
	map<string, int> b = { { "a", 1}, {"b", 2}, {"c", 3} };
    vector<int> a = { 1, 4, 6, 8, 10 };

	int sum = 0;
	for (auto m : a)
	{
		sum += m;
	}

	cout << sum;

	int vectorSum = 0;
	string concat;

	for (auto i : b)
	{
		concat += i.first;
		sum += i.second;
	}

	cout << concat;
	cout << sum;

	string aContainingString = "sadfsdfffdssa";
	int i = 0;
	for (auto c : aContainingString)
	{
		if (c == 'a')
		{
			cout << i << endl;
		}
		++i;
	}

	for (int i = 0; i < aContainingString.size(); i++)
	{
		if (aContainingString[i] == 'a')
		{
			cout << i << endl;
		}
	}

    return 0;
}
