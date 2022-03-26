#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main()
{
    int N, M;
    ifstream input("input.txt");

    if (input) {
        input >> N >> M;

        input.ignore(1);

        for (int i = 0; i < N; i++)
        {
            vector<int> temp;
            string row;

            getline(input, row, '\n');

            stringstream ss(row);

            for (int j = 0; j < M; j++)
            {
                string value;

                getline(ss, value, ',');

                int val = stoi(value);

                cout << setw(10) << value << (j < M - 1 ? " " : "");
            }

            if (i < N - 1)
            {
                cout << setw(10) << endl;
            }
        }
    }

    return 0;
}
