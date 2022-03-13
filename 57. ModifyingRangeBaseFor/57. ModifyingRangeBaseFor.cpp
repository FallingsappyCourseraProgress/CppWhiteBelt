#include <iostream>
#include <vector>
using namespace std;

void Print(const vector<int>& v, const string& title)
{
    cout << title << ": " << endl;
    for (const auto& i : v)
    {
        cout << i << " ";
    }
}

int main()
{
    vector<int> v{ 1, 2, 5, 4, 3 };

    Print(v, "init");

    cout << endl;

    for (int i = 0; i < v.size(); i++)
    {
        ++v[i];
    }

    Print(v, "inc");

    for (auto& i : v)
    {
        ++i;
    }

    Print(v, "inc");

    return 0;
}
