#include <iostream>
#include <map>
#include <set>
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
    set<string> famousPersons;

    famousPersons.insert("Stroustrup");
    famousPersons.insert("Ritchie");
    famousPersons.insert("Anton");

    PrintSet(famousPersons);

    famousPersons.erase("Anton");

    PrintSet(famousPersons);

    return 0;
}
