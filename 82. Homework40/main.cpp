#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

void ReadAllByLine(const string& path) {
    ifstream input(path);

    if (input) {
        string line;
        double d;

        while (getline(input, line))
        {
            istringstream(line) >> d;

            cout << fixed << setprecision(3) << d << endl;
        }
    }
}

void ReadAll(const string& path) {
    ifstream input(path);

    double a;

    cout << fixed << setprecision(3);

    while (input >> a) {
        cout << a << endl;
    }
}

int main()
{
    ReadAll("input.txt");

    return 0;
}
