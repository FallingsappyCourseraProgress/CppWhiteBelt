#include <iostream>
#include <vector>
#include <string>
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

std::string readuntil(std::istream& in, std::string delimiter) {
    std::string cr;
    char delim = *(delimiter.rbegin());
    size_t sz = delimiter.size(), tot;
    do {
        std::string temp;
        std::getline(in, temp, delim);
        cr += temp + delim;
        tot = cr.size();
    } while ((tot < sz) || (cr.substr(tot - sz, sz) != delimiter));
    return cr.substr(0, tot - sz);  // or return cr; if you want to keep the delimiter
}

class Date {
public:
    Date(string dateToParse) {
        std::istringstream date_stream(dateToParse);
        bool flag = true;

        flag = flag && (date_stream >> _year);
        flag = flag && (date_stream.peek() == '-');
        date_stream.ignore(1);

        flag = flag && (date_stream >> _month);
        flag = flag && (date_stream.peek() == '-');
        date_stream.ignore(1);

        flag = flag && (date_stream >> _day);
        flag = flag && date_stream.eof();

        if (!flag)
        {
            throw std::logic_error("Wrong date format: " + dateToParse);
        }
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
        if (storage.find(date) != storage.end()) {
            return storage.at(date);
        }
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
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return 0;
    }
  
    return 0;
}