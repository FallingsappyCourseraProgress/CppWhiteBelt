#include <iostream>
#include <string>
using namespace std;

int main()
{
    int x = 4;
    int y = 6;
    cout << (x + y) * (x - y);

    if (x == y) 
    {
        cout << "equal";
    }
    else 
    {
        cout << "not equal";
    }

    if (x != y)
    {
        cout << "not equal";
    }
    else
    {
        cout << "equal";
    }

    string a = "abc";
    string b = "def";


    if (a == b)
    {
        cout << "equal";
    }
    else
    {
        cout << "not equal";
    }

    if (a < b)
    {
        cout << "less";
    }
    else
    {
        cout << "not less";
    }

    return 0;
}
