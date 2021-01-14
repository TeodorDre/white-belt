//
// Created by Andrew Slesarenko on 09/01/2021.
//

#include "iostream"
#include "string"
#include "map"

using namespace std;

map<char, int> BuildCharAnagram(const string &a) {
    map<char, int> map_a;

    for (const char &i: a) {
        ++map_a[i];
    }

    return map_a;
}

string IsAnagram(const string &a, const string &b) {
    if (a.size() != b.size()) {
        return "NO";
    }

    map<char, int> map_a = BuildCharAnagram(a);
    map<char, int> map_b = BuildCharAnagram(b);

    if (map_a == map_b) {
        return "YES";
    }

    return "NO";
}

int main() {
    int operations_n;

    cin >> operations_n;

    for (int i = 0; i < operations_n; i++) {
        string a;
        string b;

        cin >> a;
        cin >> b;

        cout << IsAnagram(a, b) << endl;
    }

    return 0;
}
