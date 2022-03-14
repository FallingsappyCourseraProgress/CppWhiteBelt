#include <iostream>
using namespace std;

int main()
{
    // won't compile
    //cout << x;
    //int x = 5;

    {
        int x = 5;
        {
            cout << x;
        }

        cout << x;
    }

    // won't compile
    //cout << x;

    if (1 > 0) // for, while... etc.
    {
        int c = 5;
    }
    // won't compile
    //cout << c;

    for (int i = 0; i < 7; i++)
    {

    }

    // i not in this scope
    // cout << i;

    string s = "hello";
    {
        string s = "world";
        cout << s;
    }
    cout << s;

    return 0;
}
