#include <iostream>
#include <exception>
#include <numeric>
using namespace std;

class Rational {
public:
    Rational() {
        p = 0;
        q = 1;
    }

    Rational(int numerator, int denominator) {
        if (denominator == 0)
        {
            throw invalid_argument("Invalid argument");
        }

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

    if (d == 0)
    {
        throw domain_error("");
    }

    return Rational(n, d);
}

ostream& operator << (ostream& stream, const Rational& rational) {
    stream << rational.Numerator() << "/" << rational.Denominator();

    return stream;
}

istream& operator >> (istream& stream, Rational& r) {
    int n, d;
    char c;
    stream >> n >> c >> d;
    if (stream && c == '/') {
        r = Rational(n, d);
    }
    return stream;
}

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
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    }
    catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    }
    catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
