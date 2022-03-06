#include <iostream>
#include <vector>
using namespace std;

void PrintVector(const vector<int>& v)
{
    for (auto s : v)
    {
        cout << s << endl;
    }
}

void PrintVector(const vector<bool>& v)
{
    int i = 0;
    for (auto s : v)
    {
        cout << i << ":" << s << endl;
        i++;
    }
}

int main()
{
    vector<int> daysInAllMonths = { 31, 28, 31, 30, 31 };

    if (true) // if year is leap
    {
        daysInAllMonths[1]++;
    }

    PrintVector(daysInAllMonths);


    vector<bool> isHoliday(28, false);
    isHoliday[22] = true;

    PrintVector(isHoliday);

    isHoliday.resize(31); // добавляет элементы к исходному вектору
    isHoliday.assign(31, false); // новый вектор + расширение

    isHoliday.clear();

    return 0;
}
