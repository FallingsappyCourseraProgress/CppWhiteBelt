#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <iomanip>

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
    Date(Year newYear, Month newMonth, Day newDay) {
        _day = newDay.value;
        _month = newMonth.value;
        _year = newYear.value;
        if (_month < 1 || _month > 12) {
            throw std::logic_error("Month value is invalid: " + to_string(_month));
        }

        if (_day < 1 || _day > 31) {
            throw std::logic_error("Day value is invalid: " + to_string(_day));
        }
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

Date ParseDate(const std::string& date)
{
    std::istringstream date_stream(date);
    bool flag = true;

    int year;
    flag = flag && (date_stream >> year);
    flag = flag && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int month;
    flag = flag && (date_stream >> month);
    flag = flag && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int day;
    flag = flag && (date_stream >> day);
    flag = flag && date_stream.eof();

    if (!flag)
    {
        throw std::logic_error("Wrong date format: " + date);
    }

    return Date(Year(year), Month(month), Day(day));
}

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

std::ostream& operator << (std::ostream& stream, const Date& date)
{
    stream << std::setfill('0') << std::setw(4) << std::to_string(date.GetYear());
    stream << "-";
    stream << std::setfill('0') << std::setw(2) << std::to_string(date.GetMonth());
    stream << "-";
    stream << std::setfill('0') << std::setw(2) << std::to_string(date.GetDay());
    return stream;
}

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
        std::set<std::string> result;

        if (storage.find(date) != storage.end()) {
            result = storage.at(date);
        }

        return result;
    };

    void Print() const {
        for (auto d : storage) {
            auto foundByDateEvents = Find(d.first);

            for (auto e : foundByDateEvents) {
                cout << d.first << " " << e << endl;
            }
        }
    };
private:
    map<Date, set<string>> storage;
};

int main() {
    try
    {
        Database db;

        string combinedInput;

        map<string, Operation> allowedOperations =
        {
            { "Add", Operation::Add },
            { "Del", Operation::Del },
            { "Find", Operation::Find },
            { "Print", Operation::Print }
        };

        while (getline(cin, combinedInput))
        {
            Operation parsedOperation;

            string operationInput = "";
            string dateInput = "";
            string eventInput = "";

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
                    const Date date = ParseDate(dateInput);

                    db.AddEvent(date, eventInput);
                    break;
                }
                case Operation::Del:
                {
                    const Date date = ParseDate(dateInput);

                    if (eventInput.empty()) {
                        int deletedEventCount = db.DeleteDate(date);

                        cout << "Deleted " << deletedEventCount << " events" << endl;

                        break;
                    }

                    db.DeleteEvent(date, eventInput)
                        ? (cout << "Deleted successfully" << endl)
                        : (cout << "Event not found" << endl);

                    break;
                }
                case Operation::Find:
                {
                    const Date date = ParseDate(dateInput);

                    auto foundByDateEvents = db.Find(date);

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
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return 0;
    }
  
    return 0;
}