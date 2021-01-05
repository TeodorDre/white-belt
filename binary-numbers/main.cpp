//
// Created by Andrew Slesarenko on 25/12/2020.
//

#include "iostream"
#include "vector"

using namespace std;

int main() {
    int number;

    cin >> number;

    vector<int> binary_numbers;
    int binary_number;

    if (number == 0) {
        cout << 0;
        return 0;
    }

    do {
        binary_number = number % 2;
        binary_numbers.push_back(binary_number);

        number /= 2;
    } while (number > 0);

    int binary_numbers_size = binary_numbers.size();

    for (int i = binary_numbers_size - 1; i >= 0; i--) {
        int entry = binary_numbers[i];

        cout << entry;
    }

    return 0;
}