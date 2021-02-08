//
// Created by Andrew Slesarenko on 30/01/2021.
//

#include <vector>
#include "iostream"
#include "string"

using namespace std;

class SortedStrings {
public:
    void AddString(const string& s) {
        data.push_back(s);
    }
    vector<string> GetSortedStrings() {
        sort(begin(data), end(data));
        return data;
    }
private:
    vector<string> data;
};