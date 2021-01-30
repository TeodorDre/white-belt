//
// Created by Andrew Slesarenko on 24/12/2020.
//

#include "iostream"
#include "vector"

int main() {
    int min;
    int max;

    std::cin >> min >> max;

    if (!min || !max) {
        std::cout << "Min and max variables are required" << std::endl;

        return 0;
    }

    std::vector<int> evens;

    int counter = min;

    while (max >= counter) {
        if (counter % 2 == 0) {
            evens.push_back(counter);
        }

        counter += 1;
    }

    for (auto i : evens) {
        std::cout << i << " ";
    }

    return 0;
}