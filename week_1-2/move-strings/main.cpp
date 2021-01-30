//
// Created by Andrew Slesarenko on 31/12/2020.
//

#include "iostream"
#include "vector"

using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination) {
    for (auto const i : source) {
        destination.push_back(i);
    }

    source.clear();
}