#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <numeric>
using namespace std;

class Rational {
public:
    Rational() {
        p = 0;
        q = 1;
    }

    Rational(int numerator, int denominator) {
        if (numerator == 0)
        {
            p = 0;
            q = 1;

            return;
        }

        if ((numerator < 0 && denominator < 0) || denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }

        auto greatestCommonDivisor = gcd(numerator, denominator);

        p = numerator / greatestCommonDivisor;
        q = denominator / greatestCommonDivisor;
    }

    int Numerator() const {
        return p;
    }

    int Denominator() const {
        return q;
    }



private:
    int p;
    int q;
};

bool operator == (const Rational& lhs, const Rational& rhs)
{
    return lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator();
}

Rational operator + (const Rational& lhs, const Rational& rhs)
{
    int n = lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator();
    int d = lhs.Denominator() * rhs.Denominator();

    return Rational(n, d);
}

Rational operator - (const Rational& lhs, const Rational& rhs)
{
    int n = lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator();
    int d = lhs.Denominator() * rhs.Denominator();

    return Rational(n, d);
}

Rational operator * (const Rational& lhs, const Rational& rhs)
{
    int n = lhs.Numerator() * rhs.Numerator();
    int d = lhs.Denominator() * rhs.Denominator();

    return Rational(n, d);
}

Rational operator / (const Rational& lhs, const Rational& rhs)
{
    int n = lhs.Numerator() * rhs.Denominator();
    int d = lhs.Denominator() * rhs.Numerator();

    return Rational(n, d);
}

// Implement << and >> operators for Rational class

ostream& operator << (ostream& stream, const Rational& rational) {
    stream << rational.Numerator() << "/" << rational.Denominator();

    return stream;
}

istream& operator >> (istream& stream, Rational& rational) {
    if (!stream.good())
    {
        return stream;
    }

    int n = INT32_MIN, d = INT32_MIN;
    char delimeter;


    stream >> n;
    stream >> delimeter;
    stream >> d;

    if (delimeter != '/' || n == INT32_MIN || d == INT32_MIN)
    {
        return stream;
    }

    rational = Rational(n, d);

    return stream;
}

// Реализуйте для класса Rational оператор(ы), необходимые для использования его
// в качестве ключа map'а и элемента set'а

bool operator < (const Rational& lhs, const Rational& rhs)
{
    if (lhs.Denominator() == rhs.Denominator())
    {
        return lhs.Numerator() < rhs.Numerator();
    }

    int n1 = lhs.Numerator() * rhs.Denominator();
    int n2 = rhs.Numerator() * lhs.Denominator();


    return n1 < n2;
}

int main() {
    {
        const set<Rational> rs = { {1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2} };
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{ {1, 25}, { 1, 2 }, { 3, 4 }}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
