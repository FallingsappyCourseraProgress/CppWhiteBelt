#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void Swap(int& x, int& y)
{
	int tmp = x;
	x = y;
	y = tmp;
}

vector<int> Sort(vector<int> v)
{
	sort(begin(v), end(v));

	return v;
}

void SortByRef(vector<int>& v)
{
	sort(begin(v), end(v));
}

int main()
{
	int a = 1;
	int b = 2;
	Swap(a, b);

	cout << "a = " << a << '\n';
	cout << "b = " << b << '\n';

	vector<int> nums = { 3, 6, 1, 2, 0, 2 };
	sort(begin(nums), end(nums));
	nums = Sort(nums);
	SortByRef(nums);
	for (auto x : nums)
	{
		cout << x << " ";
	}

	return 0;
}