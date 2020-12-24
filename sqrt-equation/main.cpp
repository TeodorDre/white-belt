#include <iostream>
#include <cmath>

int main() {
    double a = 0;
    double b = 0;
    double c = 0;

    std::cin >> a >> b >> c;

    if (a != 0) {
        double disc = b * b - 4 * a * c;

        if (disc == 0) {
            std::cout << (-b) / (2 * a);
        } else if (disc > 0) {
            std::cout << (-b + sqrt(disc)) / (2 * a) << " " << (-b - sqrt(disc)) / (2 * a);
        }

    } else if (b != 0) {

        if (c != 0) {
            std::cout << (-c) / b;
        } else {
            std::cout << 0;
        }

    }

    return 0;
}