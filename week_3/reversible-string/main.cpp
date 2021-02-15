//
// Created by Andrew Slesarenko on 15/02/2021.
//

#include "iostream"
#include "string"

using namespace std;

class ReversibleString {
public:
    ReversibleString() {};

    ReversibleString(const string &str) {
        source = str;
    }

    void Reverse() {
        string reversed;

        for (int i = source.size() - 1; i >= 0; i--) {
            reversed += source[i];
        }

        source = reversed;
    }

    string ToString() const {
        return source;
    }

private:
    string source;
};
