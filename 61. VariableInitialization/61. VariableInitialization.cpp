#include <iostream>
using namespace std;

void PrintInt()
{
    int x = 0;
    cout << x << endl;
}

void PrintDouble()
{
    double pi = 3.14;
    cout << pi << endl;
}

void PrintParity(int x)
{
    string parity = x % 2 == 0 ? "even" : "odd";

    if (x % 2 == 0)
    {
        parity = "even";
    }
    else
    {
        parity = "odd";
    }

    cout << x << " is " << parity << endl;
}

string GetPositivity(int x)
{
    if (x > 0)
    {
        return "positive";
    }
    if (x < 0)
    {
        return "negative";
    }
    else
    {
        return "zero";
    }
}

void PrintPositivity(int x)
{
    // ???
    string positivity = x > 0 ? "positive" : "negative";
    positivity = GetPositivity(x);

    if (x > 0)
    {
        positivity = "positive";
    }
    if (x < 0)
    {
        positivity = "negative";
    }
    else
    {
        positivity = "zero";
    }

    cout << x << " is " << positivity << endl;
}

int main()
{
    PrintInt();
    PrintDouble();
    PrintInt();

    PrintParity(5);

    return 0;
}
