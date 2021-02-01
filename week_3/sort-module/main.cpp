//
// Created by Andrew Slesarenko on 30/01/2021.
//

#include "iostream"
#include "algorithm"
#include "vector"
#include "cmath"

using namespace std;

int main() {
    int operations_n;

    cin >> operations_n;

    vector<int> v;

    for (int i = 0; i < operations_n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end(), [](const int& a, const int& b) {
        if (abs(a) == abs(b)) {
            return a < b;
        }

        return abs(a) < abs(b);
    });

    for (const auto& i : v) {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}