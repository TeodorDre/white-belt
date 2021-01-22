//
// Created by Andrew Slesarenko on 22/01/2021.
//

#include "iostream"
#include "set"
#include "map"

using namespace std;

set<string> BuildMapValuesSet(const map<int, string> &m) {
    set<string> strings;

    for (const auto&[key, value] : m) {
        strings.insert(value);
    }

    return strings;
}
