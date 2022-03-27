#include <iostream>
#include <exception>
#include <numeric>
#include <sstream>
#include <map>
using namespace std;

enum class Operation
{
    Add,
    Substract,
    Multiply,
    Divide
};

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
        throw domain_error("Division by zero");
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

Rational MakeCalculation(istream& stream)
{
    Rational r1;
    string operation;
    Rational r2;
    Operation parsedOperation;

    stream >> r1;
    stream >> operation;
    stream >> r2;

    map<string, Operation> allowedOperations =
    {
        { "+", Operation::Add },
        { "*", Operation::Multiply },
        { "-", Operation::Substract },
        { "/", Operation::Divide }
    };

    try
    {
        parsedOperation = allowedOperations.at(operation);
    }
    catch (const std::exception&)
    {
        throw invalid_argument("unsupported operation");
    }

    switch (parsedOperation)
    {
        case Operation::Add:
        {
            return r1 + r2;
        }
        case Operation::Substract:
        {
            return r1 - r2;
        }
        case Operation::Multiply:
        {
            return r1 * r2;
        }
        case Operation::Divide:
        {
            return r1 / r2;
        }
        default:
            break;
    }
}

int main()
{
    string input;

    getline(cin, input);

    stringstream ss(input);

    try
    {
        cout << MakeCalculation(ss);
    }
    catch (invalid_argument& e) {
        cout << e.what();
    }
    catch (domain_error& e) {
        cout << e.what();
    }

    //{
    //    istringstream input("1/2 + 1/3");
    //    Rational result = MakeCalculation(input);
    //    bool correct = result == Rational(5, 6);
    //    if (!correct) {
    //        cout << "Add operation works incorrectly: " << result << endl;
    //        return 1;
    //    }
    //}

    //try {
    //    istringstream input("1/2 + 5/0");
    //    Rational result = MakeCalculation(input);
    //    cout << "Doesn't throw in case of zero denominator" << endl;
    //    return 1;
    //}
    //catch (invalid_argument&) {
    //}

    //try {
    //    istringstream input("4/5 / 0/8");
    //    Rational result = MakeCalculation(input);
    //    cout << "Doesn't throw in case of zero denominator" << endl;
    //    return 1;
    //}
    //catch (domain_error&) {
    //}

    //cout << "OK" << endl;
    
    return 0;
}
