//
// Created by Andrew Slesarenko on 22/01/2021.
//

#include "string"
#include "set"
#include "map"
#include "iostream"

using namespace std;

void Add(string& word1, string& word2,map<string, set<string>>& dict) {

}

void Count(string& word, const map<string, set<string>>& dic) {

}

void Check(string& word1, string& word2, const map<string, set<string>>& dic) {

}

int main() {
    int operations_n;

    cin >> operations_n;

    map<string, set<string>> dict;

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

            Check(word1, word2,dict);
        }
    }

    return 0;
}