#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream input("date.txt");
    string year;
    string month;
    string day;
    
    if (input) {
        getline(input, year, '-');
        getline(input, month, '-');
        getline(input, day, '-');
    }

    cout << year << ' ' << month << ' ' << day << endl;
    
    return 0;
}