#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <iomanip>

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
            throw std::logic_error("Month value is invalid: " + std::to_string(_month));
        }

        if (_day < 1 || _day > 31) {
            throw std::logic_error("Day value is invalid: " + std::to_string(_day));
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

    static Date ParseDate(const std::string& date)
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
    void AddEvent(const Date& date, const std::string& event)
    {
        storage[date].insert(event);
    };

    bool DeleteEvent(const Date& date, const std::string& event) {
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

    std::set<std::string> Find(const Date& date) const {
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
                std::cout << d.first << " " << e << std::endl;
            }
        }
    };
private:
    std::map<Date, std::set<std::string>> storage;
};

int main() {
    try
    {
        Database db;

        std::string combinedInput;

        std::map<std::string, Operation> allowedOperations =
        {
            { "Add", Operation::Add },
            { "Del", Operation::Del },
            { "Find", Operation::Find },
            { "Print", Operation::Print }
        };

        while (std::getline(std::cin, combinedInput))
        {
            Operation parsedOperation;

            std::string operationInput = "";
            std::string dateInput = "";
            std::string eventInput = "";

            std::istringstream iss(combinedInput);

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
                std::cout << "Unknown command: " << operationInput << std::endl;
                continue;
            }

            switch (parsedOperation)
            {
                case Operation::Add:
                {
                    const Date date = Date::ParseDate(dateInput);

                    db.AddEvent(date, eventInput);
                    break;
                }
                case Operation::Del:
                {
                    const Date date = Date::ParseDate(dateInput);

                    if (eventInput.empty()) {
                        int deletedEventCount = db.DeleteDate(date);

                        std::cout << "Deleted " << deletedEventCount << " events" << std::endl;

                        break;
                    }

                    db.DeleteEvent(date, eventInput)
                        ? (std::cout << "Deleted successfully" << std::endl)
                        : (std::cout << "Event not found" << std::endl);

                    break;
                }
                case Operation::Find:
                {
                    const Date date = Date::ParseDate(dateInput);

                    auto foundByDateEvents = db.Find(date);

                    for (auto e : foundByDateEvents) {
                        std::cout << e << std::endl;
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