#include <iostream>
#include <map>
using namespace std;

void PrintMap(const map<int, string>& m)
{
    cout << "Size = " << m.size() << endl;

    for (auto item : m)
    {
        cout << item.first << ": " << item.second << endl;
    }
}

void PrintMap(const map<string, int>& m)
{
    cout << "Size = " << m.size() << endl;

    for (auto item : m)
    {
        cout << item.first << ": " << item.second << endl;
    }
}

map<string, int> BuildReversedMap(const map<int, string>& m)
{
    map<string, int> result;

    for (auto item : m)
    {
        result[item.second] = item.first;
    }

    return result;
}

int main()
{
    map<int, string> events;
    events[1950] = "Bjarne Stroustrup's birth year";
    events[1941] = "Dennis Ritchie's birth year";
    events[1970] = "Unix epoch start";

    PrintMap(events);

    cout << events[1950] << endl;

    events.erase(1970);
    PrintMap(events);

    map<string, int> eventForYear = BuildReversedMap(events);

    PrintMap(eventForYear);

    cout << eventForYear["Bjarne Stroustrup's birth year"] << endl;

    return 0;
}
