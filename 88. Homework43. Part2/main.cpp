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

int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
