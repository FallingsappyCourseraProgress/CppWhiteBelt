#include <iostream>
#include <string>

using namespace std;

int main()
{
	string aContainingString = "sadfsdfffdssa";

	for (int i = 0; i < aContainingString.size(); i++)
	{
		if (aContainingString[i] == 'a')
		{
			cout << i << endl;
			break;
		}
	}

	cout << "Yes";

	return 0;
}