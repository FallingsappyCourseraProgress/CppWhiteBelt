#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream input("IOT.txt");
    string line;

    if (input.is_open()) {
        while (getline(input, line)) {
            cout << line << endl;
        }
        cout << "done!" << endl;
    } else {
        cout << "error!" << endl;
    }

    return 0;
}