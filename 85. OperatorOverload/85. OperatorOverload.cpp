#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

struct Duration {
    int hour;
    int min;

    Duration(int h = 0, int m = 0) {
        hour = h;
        min = m;
    }
};

Duration ReadDuration(istream& stream) {
    int h = 0;
    int m = 0;
    stream >> h;
    stream.ignore(1);
    stream >> m;

    return { h, m };
}

void PrintDuration(ostream& stream, const Duration& duration) {
    stream << setfill('0');
    stream << setw(2) << duration.hour << ':' << setw(2) << duration.min;
}

ostream& operator << (ostream& stream, const Duration& duration) {
    stream << setfill('0');
    stream << setw(2) << duration.hour << ':' << setw(2) << duration.min;

    return stream;
}

istream& operator >> (istream& stream, Duration& duration) {
    stream >> duration.hour;
    stream.ignore(1);
    stream >> duration.min;

    return stream;
}

int main()
{
    stringstream dur_ss("01:50");
    Duration duration = ReadDuration(dur_ss);
    PrintDuration(cout, duration);

    cout << duration << endl;

    cout << "hello" << " world";

    operator << (operator<<(cout, "hello"), " world");

    Duration iDuration{ 0, 0 };

    dur_ss >> iDuration;
    cout << iDuration << endl;

    Duration ctorDuration{ 1, 40 };

    return 0;
}

