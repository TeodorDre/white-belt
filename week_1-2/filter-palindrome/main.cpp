//
// Created by Andrew Slesarenko on 26/12/2020.
//

#include "iostream"
#include "vector"

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

vector<string> PalindromFilter(vector<string> words, int minLength) {
    vector<string> filtered_words;

    for (auto word: words) {
        if (word.size() >= minLength && IsPalindrom(word)) {
            filtered_words.push_back(word);
        }
    }

    return filtered_words;
}

int main() {
    vector<string> words = {"weew", "madam", "kazak"};

    vector<string> filtered_words = PalindromFilter(words, 5);

    for (auto i : filtered_words) {
        cout << i << endl;
    }

    return 0;
}

