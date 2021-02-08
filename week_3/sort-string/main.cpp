//
// Created by Andrew Slesarenko on 30/01/2021.
//

#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

int main() {
    int operations_n;

    cin >> operations_n;

    vector<string> v(operations_n);

    for (string& x : v) {
        cin >> x;
    }

    sort(v.begin(), v.end(), [](const string & a, const string & b) {
        string c;
        string d;

        for (char i : a) {
            c.push_back(tolower(i));
        }

        for (char i : b) {
            d.push_back(tolower(i));
        }

        return c < d;
    });

    for (const auto& i : v) {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}