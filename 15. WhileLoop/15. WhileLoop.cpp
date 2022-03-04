#include <iostream>
using namespace std;


int main()
{
    int n;

    cin >> n;

    if (n >= 1)
    {
        int sum = 0;

        while (n > 0)
        {
            sum += n;
            --n;
        }
    }
    else
    {
        cout << "Please enter positive number";
    }

    int a = 5;
    int b;

    do
    {
        cout << "Guess the number: ";
        cin >> b;
    } while (a != b);

    cout << "You are right!";

    return 0;
}
