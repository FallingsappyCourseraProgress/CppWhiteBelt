#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void ReadAll(const string& path) {
    ifstream input(path);

    if (input) {
        string line;

        while (getline(input, line))
        {
            cout << line << endl;
        }
    }
}

int main()
{
    ifstream input("date.txt");
    int year = 0;
    int month = 0;
    int day = 0;

    if (input) {
        input >> year;
        input.ignore(1);
        input >> month;
        input.ignore(1);
        input >> day;
    }

    cout << year << ' ' << month << ' ' << day << endl;

    const string path = "output.txt";

    ofstream output(path);
    output << "hello" << endl;
    ifstream inp(path);
    if (inp) {
        string line;

        while (getline(inp, line))
        {
            cout << line << endl;
        }
    }

    ReadAll(path);

    ofstream outputWriteLine(path, ios::app);
    outputWriteLine << " world!" << endl;

    return 0;
}