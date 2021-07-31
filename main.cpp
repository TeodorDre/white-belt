#include <iostream>
#include <sstream>
#include <set>

using namespace std;


int Divider(const int &n, const int &d) {
    if (n == d) {
        return n;
    } else if (n == 0) {
        return n;
    } else {
        int dividend_t = 0;
        int divider_t = 0;
        int reminder = 0;

        if (n > d) {
            dividend_t = n;
            divider_t = d;
        } else {
            dividend_t = d;
            divider_t = n;
        }

        reminder = dividend_t % divider_t;

        while (reminder != 0) {
            dividend_t = divider_t;
            divider_t = reminder;
            reminder = dividend_t % divider_t;
        }

        if (divider_t < 0) {
            return -divider_t;
        } else {
            return divider_t;
        }

    }


}


class Rational {

public:
    Rational() {
        p = 0;
        q = 1;
    }

    Rational(int numerator, int denominator) {
        if (denominator == 0) {
            throw invalid_argument("ERROR");
        } else {
            Initialize(numerator, denominator);
        }
    }

    void Initialize(const int &n, const int &d) {
        p = n;
        q = d;

        SignedFactional();
    }

    void SignedFactional() {
        if (p == 0) {
            q = 1;
        } else {
            if (q < 0) {
                p = -p;
                q = -q;
            }

            int divider = Divider(p, q);

            p /= divider;
            q /= divider;
        }
    }


    int Numerator() const {
        return p;
    }


    int Denominator() const {
        return q;
    }


    bool operator==(const Rational &a) const {
        return (a.p == p) && (a.q == q);
    }

    bool operator>(const Rational &a) const {
        if ((p * a.q) > (q * a.p)) {
            return true;
        } else {
            return false;
        }

    }

    bool operator<(const Rational &a) const {
        if ((p * a.q) < (q * a.p)) {
            return true;
        } else {
            return false;
        }
    }

    Rational operator+(const Rational &x) {
        Rational result;

        if (x.q == q) {
            result.p = x.p + p;
            result.q = x.q;
        } else {
            result.p = (x.p * q) + (p * x.q);
            result.q = x.q * q;
        }

        result.SignedFactional();

        return result;

    }

    Rational operator-(const Rational &x) {
        Rational result;

        if (x.q == q) {
            result.p = p - x.p;
            result.q = x.q;
        } else {
            result.p = (p * x.q) - (x.p * q);
            result.q = x.q * q;
        }

        result.SignedFactional();

        return result;

    }


private:
    int p;
    int q;
};


istream &operator>>(istream &stream, Rational &r) {
    int p_t, q_t;

    stream >> p_t;
    stream.ignore(1);
    stream >> q_t;

    r.Initialize(p_t, q_t);

    return stream;
}


ostream &operator<<(ostream &stream, const Rational &r) {
    stream << r.Numerator() << '/' << r.Denominator();
    return stream;
}


Rational operator*(const Rational &left, const Rational &right) {
    Rational result;
    result.Initialize(
            (right.Numerator() * left.Numerator()),
            (right.Denominator() * left.Denominator())
    );

    return result;
}


Rational operator/(const Rational &left, const Rational &right) {
    if (right.Numerator() == 0) {
        throw domain_error("WTF?");
    } else {
        Rational result;

        result.Initialize(
                (left.Numerator() * right.Denominator()),
                (left.Denominator() * right.Numerator())
        );

        return result;
    }

}

int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

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

    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;

        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 5;
        }
    }

    {
        istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
            << r1 << " " << r2 << " " << r3 << endl;

            return 6;
        }
    }

    cout << "OK" << endl;
    return 0;
}