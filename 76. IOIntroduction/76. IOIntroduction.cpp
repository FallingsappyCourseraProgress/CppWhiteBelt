#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream input("IO.txt");

    string line;

    //getline(input, line);
    //cout << line << endl;

    //getline(input, line);
    //cout << line << endl;

    //getline(input, line);
    //cout << line << endl;

    while (getline(input, line)) {
        cout << line << endl;
    }

    return 0;
}