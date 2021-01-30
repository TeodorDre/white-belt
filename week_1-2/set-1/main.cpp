//
// Created by Andrew Slesarenko on 22/01/2021.
//

#include "iostream"
#include "set"

using namespace std;

int main() {
    int n;

    cin >> n;

    set<string> c;

    for (int i = 0; i < n; i++) {
        string a;

        cin >> a;

        c.insert(a);
    }

    cout << c.size();

    return 0;
}