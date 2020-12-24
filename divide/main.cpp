//
// Created by Andrew Slesarenko on 24/12/2020.
//

#include "iostream"

int main() {
    int a, b;

    std::cin >> a >> b;

    if (b == 0) {
        std::cout << "Impossible";
        return 0;
    }

    int result = a / b;

    std::cout << result;

    return 0;
}