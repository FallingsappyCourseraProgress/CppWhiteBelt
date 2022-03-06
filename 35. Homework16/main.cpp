#include <iostream>
#include <vector>
using namespace std;

vector<int> Reversed(const vector<int>& v)
{
    vector<int> reversed;

    for (int i = v.size() - 1; i >= 0; i--)
    {
        reversed.push_back(v[i]);
    }

    return reversed;
}

int main()
{
    vector<int> reversed;

    reversed =  Reversed({ 1, 5, 3, 4, 2 });

    bool isLast = false;

    for (int i = 0; i < reversed.size(); i++)
    {
        if (i == (reversed.size() - 1))
        {
            isLast = true;
        }

        cout << reversed[i] << (isLast ? "" : ", ");
    }

    return 0;
}
