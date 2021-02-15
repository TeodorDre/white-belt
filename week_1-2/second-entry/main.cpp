`//
// Created by Andrew Slesarenko on 24/12/2020.
//

#include "iostream"
#include "map"
#include "vector"

using namespace std;

int main() {
    string input_string;
    char entry_letter = 'f';

    cin >> input_string;

    if (input_string.empty()) {
        cout << "String is required";

        return 0;
    }

    vector<int> entries;

    for (int i = 0; i < input_string.size(); i += 1) {
        char letter = input_string[i];

        if (letter == entry_letter) {
            entries.push_back(i);
        }
    }

    int result = -2;

    int entries_size = entries.size();

    if (entries_size == 0) {
        result = -2;
    } else if (entries_size == 1) {
        result = -1;
    } else if (entries_size > 1) {
        int second_entry = entries[1];

        result = second_entry;
    }

    std::cout << result;

    return 0;
}