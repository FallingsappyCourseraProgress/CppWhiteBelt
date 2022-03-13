#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int Min(int a, int b)
{
    return a < b ? a : b;
}

int Max(int a, int b)
{
    return a > b ? a : b;
}

void Print(const vector<int>& v, const string& title)
{
    cout << title << ": " << endl;
    for (auto i : v)
    {
        cout << i << " ";
    }
}

int main()
{
    cout << Min(2, 3) << endl;
    cout << min(2, 3) << endl;
    cout << Max(2, 3) << endl;
    cout << max(2, 3) << endl;

    string s1 = "abc";
    string s2 = "bca";

    cout << min(s1, s2) << endl;
    cout << max(s1, s2) << endl;

    vector<int> v{ 1, 3, 2 };
    Print(v, "initial");

    cout << endl;

    sort(begin(v), end(v));
    Print(v, "sorted");

    return 0;
}