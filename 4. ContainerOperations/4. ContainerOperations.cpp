#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string s = "safgsdf";

	for (char c : s)
	{
		cout << c << ", ";
	}

	cout << endl;

	vector<int> nums = {1, 5, 2, 3, 5};
	int quantity = 0;

	for (int c : nums)
	{
		cout << c << ", ";
	}

	cout << endl;

	for (auto c : nums)
	{
		cout << c << ", ";

		if (c == 5)
		{
			quantity++;
		}
	}

	cout << endl << "There is: " << quantity << " 5's in vector";




	int quantityWithBuiltInAlgorithm = count(begin(nums), end(nums), 5);
	cout << endl << "There is: " << quantityWithBuiltInAlgorithm << " 5's in vector";

	sort(begin(nums), end(nums));

	cout << endl;

	for (auto c : nums)
	{
		cout << c << ", ";
	}

    return 0;
}
