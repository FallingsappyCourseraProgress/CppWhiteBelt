#include <iostream>
using namespace std;

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

struct Date
{
    int day;
    int month;
    int year;

    Date(Day newDay, Month newMonth, Year newYear)
    {
        day = newDay.value;
        month = newMonth.value;
        year = newYear.value;
    }
};

void PrintDate(const Date& date)
{
    cout << date.day << "." << date.month << "." << date.year << endl;
}

int main()
{
    // writing explicit constructor will prevent this behavior
    // Date date = { { 1 }, {1}, {2017} };

    // this allowed aswell
    Date dateExplicit = { Day{ 1 }, Month{1}, Year{2017} };

    Date date = { Day(1), Month(1), Year(2017)};

    PrintDate(date);

    return 0;
}
