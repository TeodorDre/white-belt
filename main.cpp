#include <cmath>
#include "iostream"

void to_sqrt(const int a, const int b, const int c) {
    double d = b * b - 4 * a * c;

    double x1 = ((b * -1) - sqrt(d)) / (a * c);
    double x2 = ((b * -1) + sqrt(d)) / (a * c);

    std::cout << x2 << " " << x1;
}

int main() {
    int a, b, c;

    std::cin >> a;
    std::cin >> b;
    std::cin >> c;

    to_sqrt(a, b, c);

    return 0;
}