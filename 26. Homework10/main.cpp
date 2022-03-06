#include <iostream>
using namespace std;

int Factorial(int a)
{
	int factorial = 1;

	if (a < 0)
	{
		return factorial;
	}

	for (int i = 1; i <= a; i++)
	{
		factorial *= i;
	}

	return factorial;
}

int main()
{
	int x;

	cin >> x;

	cout << Factorial(x);

    return 0;
}