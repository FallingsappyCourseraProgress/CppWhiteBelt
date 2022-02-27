#include <iostream>
#include <cmath>
using namespace std;

void CalculateRoots(double a, double b, double c, double* x1, double* x2)
{
    if (a == 0)
    {
        *x1 = -c / b;
    }
    else
    {
        *x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
        *x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
    }
}

void PrintRoots(double a, double b, double c, double* x1, double* x2)
{
    if ((isnan(*x1) && isnan(*x2)) || (a == 0 && b == 0) || (a == 0 && b == 0 && c == 0))
    {
        return;
    }

    if (*x1 != *x2)
    {
        if (!isnan(*x1) && !isnan(*x2))
        {
            if (a == 0)
            {
                cout << *x1;
            }
            else
            {
                cout << *x1 << " " << *x2;
            }
        }
        else if (isnan(*x1))
        {
            cout << *x2;
        }
        else
        {
            cout << *x1;
        }
    }
    else
    {
        cout << *x1;
    }
}

int main()
{
    double a, b, c, x1, x2;

    cin >> a >> b >> c;

    CalculateRoots(a, b, c, &x1, &x2);
    PrintRoots(a, b, c, &x1, &x2);

    return 0;
}
