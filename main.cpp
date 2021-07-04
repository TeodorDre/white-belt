#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <exception>

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
            throw invalid_argument("Invalid argument");
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

    const bool operator==(const Rational &a) const {
        if ((a.p == p)) {
            return true;
        } else {
            return false;
        }
    }

    const bool operator>(const Rational &a) const {
        if ((p * a.q) > (q * a.p)) {
            return true;
        } else {
            return false;
        }
    }

    const bool operator<(const Rational &a) const {
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
        throw domain_error("Invalid argument");
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

    cout << "OK" << endl;
    return 0;
}