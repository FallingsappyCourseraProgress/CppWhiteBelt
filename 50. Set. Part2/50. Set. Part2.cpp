#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

void PrintSet(const set<string>& famousPersons)
{
    cout << "Set size: " << famousPersons.size() << endl;

    for (auto x : famousPersons)
    {
        cout << x << endl;
    }
}

int main()
{
    set<string> monthNames = { "January", "February", "March", "March", "April", "May", "June", "July", "August" };
    set<string> monthNames1 = { "January", "February", "March", "March", "April", "May", "June", "July", "August" };

    cout << (monthNames == monthNames1) << endl;

    cout << monthNames.count("January") << endl;

    vector<string> v = { "a", "b", "a" };
    set<string> s(begin(v), end(v));
    PrintSet(s);

    return 0;
}
