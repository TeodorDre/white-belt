//
// Created by Andrew Slesarenko on 25/12/2020.
//

#include "iostream"
#include "string"

using namespace std;

bool IsPalindrom(string word) {
    if (word.empty()) {
        return true;
    }

    int word_size = word.size() - 1;

    bool is_palindrom = false;

    for (int i = 0; i <= word_size; i++) {
        char entry_from_start = word[i];
        char entry_from_end = word[word_size - i];

        if (entry_from_end == entry_from_start) {
            is_palindrom = true;
        } else {
            is_palindrom = false;
            break;
        }
    }

    return is_palindrom;
}

int main() {
    string word;
    cin >> word;

    cout << IsPalindrom(word);

    return 0;
}
