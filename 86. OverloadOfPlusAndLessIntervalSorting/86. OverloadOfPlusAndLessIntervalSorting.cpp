#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Duration {
    int hour;
    int min;

    Duration(int h = 0, int m = 0) {
        int total = h * 60 + m;

        hour = total / 60;
        min = total % 60;
    }
};

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

Duration operator+(const Duration& lhs, const Duration& rhs)
{
    return Duration(lhs.hour + rhs.hour, lhs.min + rhs.min);
}

bool operator < (const Duration& lhs, const Duration& rhs)
{
    if (lhs.hour == rhs.hour) {
        return lhs.min < rhs.min;
    }

    return lhs.hour < rhs.hour;
}

void PrintVector(vector<Duration>& durs)
{
    for (const auto& d : durs)
    {
        cout << d << ' ';
    }
    cout << endl;
}

int main()
{
    Duration duration1(4, 5);
    Duration duration2(0, 5);

    cout << duration1 + duration2 << endl;

    Duration duration3 = duration1 + duration2;

    vector<Duration> v{ duration3, duration1, duration2 };

    sort(begin(v), end(v));

    return 0;
}
