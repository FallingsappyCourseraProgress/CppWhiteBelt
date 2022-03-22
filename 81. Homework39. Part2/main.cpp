#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void ReadAll(const string& path, const string& outputPath) {
    ifstream input(path);

    if (input) {
        string line;

        ofstream outputWriteLine(outputPath);

        while (getline(input, line))
        {
            ofstream outputWriteLine(outputPath, ios::app);
            outputWriteLine << line << endl;
        }
    }
}

int main()
{
    const string inputPath = "input.txt";
    const string outputPath = "output.txt";

    ReadAll(inputPath, outputPath);

    return 0;
}