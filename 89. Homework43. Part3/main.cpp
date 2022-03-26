#include <iostream>
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

// Реализуйте для класса Rational операторы ==, + и -

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

// Реализуйте для класса Rational операторы * и /

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

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
