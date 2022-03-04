#include <iostream>
using namespace std;

int main()
{
    int a, b;

    cin >> a >> b;

    if (a == b)
    {
        cout << "equal" << endl;
        cout << a;
    }
    else
    {
        cout << "not equal" << endl;
        cout << a << " " << b;
    }

    int x = -1;

    if (x >= 0)
    {
        if (a > 0)
        {
            cout << "positive";
        }
    }
    else
    {
        cout << "negative";
    }

    return 0;
}