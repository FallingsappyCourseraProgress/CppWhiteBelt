﻿#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <exception>

using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

void EnsureNextSymbolAndSkip(stringstream& stream) {
    if (stream.peek() != '/') {
        //throw exception();

        stringstream ss;

        ss << "expected / but has: " << char (stream.peek());
        throw runtime_error(ss.str());
    }

    stream.ignore(1);
}

Date ParseDate(const string& s) {
    stringstream stream(s);

    Date date;

    stream >> date.year;

    EnsureNextSymbolAndSkip(stream);
    stream >> date.month;

    EnsureNextSymbolAndSkip(stream);
    stream >> date.day;

    return date;
}

int main()
{
    string date_str = "2017/01/25";
    Date date = ParseDate(date_str);
    cout << setw(2) << setfill('0') << date.day << '.'
         << setw(2) << setfill('0') << date.month << '.'
         << setw(2) << setfill('0') << date.year << endl;

    string date_str_wrong = "2017d01/25";

    try
    {
        Date date = ParseDate(date_str_wrong);
    }
    catch (const std::exception& ex)
    {
        cout << "exception happens" << ex.what();
    }

    return 0;
}
