#include <iostream>
using namespace std;

int main()
{
    int a = 11;
    int b = 3;
    double c = 3;

    cout << a / b;
    cout << a / c;

    int x = 5;
    x = x + 2;
    x += 2;
    x -= 2;
    x *= 2;
    x /= 2;

    x += 1;
    x++;
    ++x;

    cout << x;

    int d = x++;
    int z = ++x;

    cout << endl;

    cout << d << endl;
    cout << z << endl;
    
    return 0;
}