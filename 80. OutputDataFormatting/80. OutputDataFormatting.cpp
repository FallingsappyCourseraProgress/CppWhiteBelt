#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

void Print(const vector<string>& names, const vector<double> values, int width) {
    for (const auto& n : names) {
        cout << setw(width) << n << ' ';
    }

    cout << endl;
    cout << fixed << setprecision(2);


    for (const auto& v : values) {
        cout << setw(width) << v << ' ';
    }
}

int main()
{
    vector<string> names = { "a", "b", "c" };
    vector<double> values = { 5, 0.01, 0.000005 };

    for (const auto& n : names) {
        cout << setw(10) << n << ' ';
    }

    cout << endl;
    cout << fixed << setprecision(2);
    //cout << setw(10);

    for (const auto& v : values) {
        cout << setw(10) << v << ' ';
    }

    cout << setfill('.');
    cout << left;
    Print(names, values, 10);

    return 0;
}
