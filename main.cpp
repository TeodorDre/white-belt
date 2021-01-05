//
// Created by Andrew Slesarenko on 05/01/2021.
//

#include "iostream"
#include "vector"

using namespace std;

int main() {
    int days_count;
    cin >> days_count;

    vector<int> day_degrees;

    while (days_count > 0) {
        int degree;
        cin >> degree;

        day_degrees.push_back(degree);

        days_count--;
    }

    for (auto& degree: day_degrees) {
        std::cout << degree;
    }

    return 0;
}