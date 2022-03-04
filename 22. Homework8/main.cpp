#include <iostream>

using namespace std;

int main()
{
    int x, y, c, nod = 0;
    
    cin >> x >> y;

    // Not optimal
    //c = x < y ? x : y;

    //for (int i = 1; i <= c; i++)
    //{
    //    if (c % i == 0 && (c == x ? y : x) % i == 0)
    //    {
    //        nod = i;
    //    }
    //}

    while (x > 0 && y > 0)
    {
        if (x > y)
        {
            x = x % y;
        }
        else
        {
            y = y % x;
        }
    }

    cout << x + y;

    return 0;
}
