#include <iostream>
#include <set>
#include <sstream>

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
        if (d == 0) {
            throw invalid_argument("Invalid argument");
        }

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

    if (!(stream >> p_t)) {
        return stream;
    }

    if (stream.get() == '/') {
        stream.unget();
    }

    if (!stream.ignore(1)) {
        return stream;
    }

    if (!(stream >> q_t)) {
        return stream;
    }

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
        throw domain_error("Division by zero");
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
    try {
        Rational r1;
        Rational r2;
        char operation_type;

        cin >> r1;
        cin >> operation_type;
        cin >> r2;

        switch (operation_type) {
            case '+':
                cout << r1 + r2;
                break;
            case '-':
                cout << r1 - r2;
                break;
            case '*':
                cout << r1 * r2;
                break;
            case '/':
                cout << r1 / r2;
                break;
            default:
                return 0;
        }
    } catch (const invalid_argument &e) {
        cout << e.what();
    } catch (const domain_error &e) {
        cout << e.what();
    }

    return 0;
}
