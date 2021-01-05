//
// Created by Andrew Slesarenko on 31/12/2020.
//

#include "iostream"
#include "vector"

using namespace std;

vector<int> Reversed(const vector<int>& v) {
    vector<int> result = {};

    result.reserve(v.size());

    for (int i = v.size() - 1; i >= 0; i--) {
        int entry = v[i];

        result.push_back(entry);
    }

    return result;
};
