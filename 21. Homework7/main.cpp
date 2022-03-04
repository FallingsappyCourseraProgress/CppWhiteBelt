#include <iostream>

using namespace std;

int main()
{
    string word;

    cin >> word;

    int fCounter = 0;

    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] == 'f')
        {
            fCounter++;
        }

        if (fCounter == 2)
        {
            cout << i;
            break;
        }
    }


    if (fCounter == 1)
    {
        cout << -1;
    }

    if (fCounter == 0)
    {
        cout << -2;
    }

    return 0;
}
