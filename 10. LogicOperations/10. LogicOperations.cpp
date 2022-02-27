#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main()
{
    int a = 3;
    int b = 5;

    if (a < b)
    {
        cout << "a is lesser than b";
    }

    string as = "fire";
    string bs = "water";

    if (as < bs)
    {
        cout << "a is lesser than b";
    }

    vector<string> av = { "fire", "water" };
    vector<string> bv = { "for", "air" };

    if (av < bv)
    {
        cout << "a is lesser than b";
    }

    map<string, int> ad = { { "one", 1}, {"two", 2} };
    map<string, int> bd = { { "three", 3}, {"four", 4} };

    if (ad < bd)
    {
        cout << "a is lesser than b";
    }

    string s = "abc";

    if (!s.empty() && s < "zzz") // конъюнкция
    {
        cout << s;
    }

    if (!s.empty() || s < "zzz") // дизъюнкция
    {
        cout << s;
    }

    return 0;
}
