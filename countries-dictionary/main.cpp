//
// Created by Andrew Slesarenko on 11/01/2021.
//

#include "iostream"
#include "string"
#include "map"

using namespace std;

void ChangeCapital(const string& country_name, const string& new_capital, map<string, string>& dict) {
    if (dict.count(country_name) == 1 && dict[country_name] == new_capital) {
        cout << "Country " + country_name << " hasn't changed its capital" << endl;
        return;
    }

    if (dict.count(country_name) == 0) {
        dict[country_name] = new_capital;

        cout << "Introduce new country " + country_name << " with capital " << new_capital << endl;
        return;
    }

    if (dict.count(country_name) == 1 && dict[country_name] != new_capital) {
        cout << "Country " + country_name << " has changed its capital from " << dict[country_name] << " to " << new_capital << endl;
        dict[country_name] = new_capital;
    }
}

void RenameCountry(const string& old_country_name, const string& new_country_name, map<string, string>& dict) {
    if (old_country_name == new_country_name || dict.count(new_country_name) == 1 || dict.count(old_country_name) == 0) {
        cout << "Incorrect rename, skip" << endl;
        return;
    }

    if (dict.count(old_country_name) == 1) {
        dict[new_country_name] = dict[old_country_name];
        dict.erase(old_country_name);

        cout << "Country " << old_country_name << " with capital " << dict[new_country_name] << " has been renamed to " << new_country_name << endl;
    }
}

void PrintCountryInfo(const string& country_name, map<string, string>& dict) {
    if (dict.count(country_name) == 0) {
        cout << "Country " << country_name << " doesn't exist" << endl;
    } else {
        cout << "Country " << country_name << " has capital " << dict[country_name] << endl;
    }
}

void Dump(map<string, string>& dict) {
    if (dict.empty()) {
        cout << "There are no countries in the world" << endl;
        return;
    }

    for (const auto& [key, value] : dict) {
        cout << key << "/" << value << " ";
    }

    cout << endl;
}

int main () {
    int operations_n;

    const string CHANGE_COMMAND = "CHANGE_CAPITAL";
    const string RENAME_COMMAND = "RENAME";

    const string ABOUT_COMMAND = "ABOUT";
    const string DUMP_COMMAND = "DUMP";

    cin >> operations_n;

    map<string, string> dict;

    for (int i = 0; i < operations_n; i++) {
        string a;
        string b;
        string c;

        cin >> a;

        if (a == CHANGE_COMMAND) {
            cin >> b;
            cin >> c;

            ChangeCapital(b, c, dict);
        } else if (a == RENAME_COMMAND) {
            cin >> b;
            cin >> c;

            RenameCountry(b, c, dict);
        } else if (a == ABOUT_COMMAND) {
            cin >> b;

            PrintCountryInfo(b, dict);
        } else if (a == DUMP_COMMAND) {
            Dump(dict);
        }
    }

    return 0;
}
