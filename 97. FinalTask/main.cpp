#include <iostream>
#include <string>
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

class Date {
public:
    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;
};

bool operator<(const Date& lhs, const Date& rhs);

class Database {
public:
    void AddEvent(const Date& date, const string& event);
    bool DeleteEvent(const Date& date, const string& event);
    int  DeleteDate(const Date& date);

    void Find(const Date& date) const;

    void Print() const;
private:
    map<Date, set<string>> storage;
};

int main() {
    Database db;

    Operation parsedOperation;

    map<string, Operation> allowedOperations =
    {
        { "Add", Operation::Add },
        { "Del", Operation::Del },
        { "Find", Operation::Find },
        { "Print", Operation::Print }
    };

    string command;
    while (getline(cin, command)) 
    {
        try
        {
            parsedOperation = allowedOperations.at(command);
        }
        catch (const std::exception&)
        {
            throw invalid_argument("unsupported operation");
        }

        switch (parsedOperation)
        {
        case Operation::Add:
            /* code */
            break;
        case Operation::Del:
            /* code */
            break;
        case Operation::Find:
            /* code */
            break;
        case Operation::Print:
            /* code */
            break;
        default:
            break;
        }
    }

    return 0;
}