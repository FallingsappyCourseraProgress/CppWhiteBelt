#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <map>

using namespace std;

// Реализуйте функции и методы классов и при необходимости добавьте свои

enum class Operation
{
    Add,
    Del,
    Find,
    Print
};

struct Day
{
    int value;

    explicit Day(int value)
    {
        this->value = value;
    }
};

struct Month
{
    int value;

    explicit Month(int value)
    {
        this->value = value;
    }
};

struct Year
{
    int value;

    explicit Year(int value)
    {
        this->value = value;
    }
};

class Date {
public:
    Date(string dateToParse) {

    }

    Date(Day newDay, Month newMonth, Year newYear) {
        _day = newDay.value;
        _month = newMonth.value;
        _year = newYear.value;
    }

    int GetYear() const {
        return _year;
    };
    int GetMonth() const {
        return _month;
    };
    int GetDay() const {
        return _day;
    };

private:
    int _year;
    int _month;
    int _day;
};

bool operator < (const Date& lhs, const Date& rhs)
{
    if (lhs.GetYear() == rhs.GetYear()) {
        if (lhs.GetMonth() == rhs.GetMonth()) {
            if (lhs.GetDay() == rhs.GetDay()) {
                return false;
            }

            return lhs.GetDay() < rhs.GetDay();
        }

        return lhs.GetMonth() < rhs.GetMonth();
    }

    return lhs.GetYear() < rhs.GetYear();
};

class Database {
public:
    void AddEvent(const Date& date, const string& event)
    {
        storage[date].insert(event);
    };

    bool DeleteEvent(const Date& date, const string& event) {
        if (storage.find(date) != storage.end()) {
            if (storage[date].find(event) != storage[date].end()) {
                storage[date].erase(event);

                return true;
            }
        }

        return false;
    };

    int DeleteDate(const Date& date) {
        int eventCount = 0;
        
        if (storage.find(date) != storage.end()) {
            eventCount = storage[date].size();

            storage[date].clear();

            return eventCount;
        }

        return 0;
    };

    set<string> Find(const Date& date) const {
        if (storage.find(date) != storage.end()) {
            return storage.at(date);
        }
    };

    void Print() const {
        for (auto d : storage) {
            auto foundByDateEvents = Find(d.first);

            for (auto e : foundByDateEvents) {
                cout << e << endl;
            }
        }
    };
private:
    map<Date, set<string>> storage;
};

int main() {
    Database db;

    string combinedInput;

    string operationInput = "";
    string dateInput = "";
    string eventInput = "";

    Operation parsedOperation;

    map<string, Operation> allowedOperations =
    {
        { "Add", Operation::Add },
        { "Del", Operation::Del },
        { "Find", Operation::Find },
        { "Print", Operation::Print }
    };

    while (getline(cin, combinedInput))
    {
        istringstream iss(combinedInput);

        if (iss.rdbuf()->in_avail() == 0)
        {
            continue;
        }

        iss >> operationInput >> dateInput >> eventInput;

        try
        {
            parsedOperation = allowedOperations.at(operationInput);
        }
        catch (const std::exception&)
        {
            cout << "Unknown command: " << operationInput << endl;
            continue;
        }

        switch (parsedOperation)
        {
            case Operation::Add:
            {
                db.AddEvent(Date(dateInput), eventInput);
                break;
            }
            case Operation::Del:
            {
                if (eventInput.empty()) {
                    int deletedEventCount = db.DeleteDate(Date(dateInput));

                    cout << "Deleted " << deletedEventCount << " events" << endl;

                    break;
                }

                db.DeleteEvent(Date(dateInput), eventInput)
                    ? (cout << "Deleted successfully" << endl)
                    : (cout << "Event not found" << endl);

                break;
            }
            case Operation::Find:
            {
                auto foundByDateEvents = db.Find(Date(dateInput));

                for (auto e : foundByDateEvents) {
                    cout << e << endl;
                }

                break;
            }
            case Operation::Print:
            {
                db.Print();
                break;
            }
            default:
            {
                break;
            }
        }
    }

    return 0;
}