//
// Created by Andrew Slesarenko on 22/01/2021.
//

#include "string"
#include "set"
#include "map"
#include "iostream"

using namespace std;

using Synonyms = map<string, set<string>>;

void Add(const string &word1, const string &word2, Synonyms &dict) {
    set<string> words;

    words.insert(word1);
    words.insert(word2);

    dict[word1] = words;
    dict[word2] = words;
}

void Count(const string &word, const Synonyms &dict) {
    int synonyms = 0;

    for (const auto&[key, value] : dict) {
        if (value.count(word) == 1) {
            synonyms++;
        }
    }

    cout << synonyms << endl;
}

void Check(const string &word1, const string &word2, const Synonyms  &dict) {
    bool result = false;

    string text = result ? "YES" : "NO";

    cout << text << endl;
}

int main() {
    int operations_n;

    cin >> operations_n;

    Synonyms dict;

    for (int i = 0; i < operations_n; i++) {
        string command;

        cin >> command;

        if (command == "ADD") {
            string word1;
            string word2;

            cin >> word1;
            cin >> word2;

            Add(word1, word2, dict);
        } else if (command == "COUNT") {
            string word;
            cin >> word;

            Count(word, dict);
        } else if (command == "CHECK") {
            string word1;
            string word2;

            cin >> word1;
            cin >> word2;

            Check(word1, word2, dict);
        }
    }

    return 0;
}