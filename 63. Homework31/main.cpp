#include <iostream>
#include <map>
using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        _firstNames[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        _lastNames[year] = last_name;
    }
    string GetFullName(int year) {
        string actualFirstName = "", actualLastName = "";

        for (auto fN : _firstNames)
        {
            if (fN.first <= year)
            {
                actualFirstName = fN.second;
            }
        }

        for (auto lN : _lastNames)
        {
            if (lN.first <= year)
            {
                actualLastName = lN.second;
            }
        }


        if (actualFirstName == "" && actualLastName == "")
        {
            return "Incognito";
        }

        if (actualFirstName == "" && actualLastName != "")
        {
            return actualLastName + " with unknown first name";
        }

        if (actualFirstName != "" && actualLastName == "")
        {
            return actualFirstName + " with unknown last name";
        }
        
        return actualFirstName + " " + actualLastName;
    }
private:
    map<int, string> _firstNames;
    map<int, string> _lastNames;;
};

int main()
{
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}

