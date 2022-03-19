#include <iostream>
#include <map>
using namespace std;

// если имя неизвестно, возвращает пустую строку
string FindNameByYear(const map<int, string>& names, int year) {
    string name;  // изначально имя неизвестно

    // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
    for (const auto& item : names) {
        // если очередной год не больше данного, обновляем имя
        if (item.first <= year) {
            name = item.second;
        }
        else {
            // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
            break;
        }
    }

    return name;
}

string GetHistory(const map<int, string>& names, const string& name, const int year)
{
    string history = "";

    if (names.size() == 1)
    {
        return history;
    }

    for (auto it = names.rbegin(); it != names.rend(); ++it) {
        if (it == names.rbegin())
        {
            continue;
        }

        if (history.size() == 0 && name == (*it).second)
        {
            continue;
        }

        if ((*prev(it)).second == (*it).second || (*it).first > year)
        {
            continue;
        }

        history += (history.size() == 0 ? "" : ", ") + (*it).second;
    }

    if (history.size() > 0)
    {
        return " (" + history + ")";
    }

    return history;
}

class Person {
public:
    Person(string firstName, string lastName, int year)
    {
        _firstNames[year] = firstName;
        _lastNames[year] = lastName;
        birthYear = year;
    }

    void ChangeFirstName(int year, const string& firstName) 
    {
        if (year < birthYear)
        {
            return;
        }

        _firstNames[year] = firstName;
    }
    void ChangeLastName(int year, const string& lastName)
    {
        if (year < birthYear)
        {
            return;
        }

        _lastNames[year] = lastName;
    }
    string GetFullName(int year) const 
    {
        return GetFullName(year, false);
    }
    string GetFullNameWithHistory(int year) const 
    {
        return GetFullName(year, true);
    }
private:
    map<int, string> _firstNames;
    map<int, string> _lastNames;
    int birthYear;

    string GetFullName(int year, bool isWithHistory) const
    {
        if (year < birthYear)
        {
            return "No person";
        }

        // получаем имя и фамилию по состоянию на год year
        const string firstName = FindNameByYear(_firstNames, year);
        const string lastName = FindNameByYear(_lastNames, year);

        // если и имя, и фамилия неизвестны
        if (firstName.empty() && lastName.empty()) {
            return "Incognito";

            // если неизвестно только имя
        }
        else if (firstName.empty()) {
            return lastName + (isWithHistory ? GetHistory(_lastNames, lastName, year) : "") + " with unknown first name";

            // если неизвестна только фамилия
        }
        else if (lastName.empty()) {
            return firstName + (isWithHistory ? GetHistory(_firstNames, firstName, year) : "") + " with unknown last name";

            // если известны и имя, и фамилия
        }
        else {
            return firstName + (isWithHistory ? GetHistory(_firstNames, firstName, year) : "") + " " + lastName + (isWithHistory ? GetHistory(_lastNames, lastName, year) : "");
        }
    }
};

int main() {
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}