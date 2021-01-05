//
// Created by Andrew Slesarenko on 31/12/2020.
//

#include "iostream"
#include "vector"

using namespace std;

void Reverse(vector<int> &v) {
    vector<int> temp = {};

    temp.reserve(v.size());

    for (int i = v.size() - 1; i >= 0; i--) {
        int entry = v[i];

        temp.push_back(entry);
    }

    v.clear();

    for (const auto i : temp) {
        v.push_back(i);
    }

    temp.clear();
}
