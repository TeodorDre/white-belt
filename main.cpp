//
// Created by Andrew Slesarenko on 30/01/2021.
//

#include <vector>
#include "iostream"
#include "string"
#include "map"

using namespace std;

struct PersonItem {
    string firstName;
    string lastName;
};

class Person {
public:
    void ChangeFirstName(int year, const string &first_name) {
        // добавить факт изменения имени на first_name в год year
        PersonItem &data = years[year];
        years[year].firstName = first_name;
    }

    void ChangeLastName(int year, const string &last_name) {
        // добавить факт изменения фамилии на last_name в год year
        PersonItem &data = years[year];
        years[year].lastName = last_name;
    }

    string GetFullNameWithHistory(int year) {
        PersonItem &data = years[year];

        string first_name = data.firstName;
        string last_name = data.lastName;

        vector<string> history_first_names;
        vector<string> history_last_names;

        for (const auto&[key, value]: years) {
            if (key <= year) {
                if (!value.firstName.empty()) {
                    first_name = value.firstName;

                    string historyFirstName;

                    if (!history_first_names.empty()) {
                       historyFirstName = history_first_names.back();
                    }

                    if (historyFirstName != value.firstName) {
                        history_first_names.push_back(value.firstName);
                    }
                }

                if (!value.lastName.empty()) {
                    last_name = value.lastName;

                    string historyLastName;

                    if (!history_last_names.empty()) {
                        historyLastName = history_first_names.back();
                    }

                    if (historyLastName != value.lastName) {
                        history_last_names.push_back(value.lastName);
                    }
                }
            }
        }

        bool is_empty_first_name = first_name.empty();
        bool is_empty_last_name = last_name.empty();

        if (is_empty_first_name && is_empty_last_name) {
            return "Incognito";
        }

        if (is_empty_first_name) {
            return last_name + " with unknown first name";
        }

        if (is_empty_last_name) {
            return first_name + " with unknown last name";
        }

        for (const auto& firstName: history_first_names) {
            cout << firstName;
        }

        for (const auto& lastName: history_last_names) {
            cout << lastName;
        }

        return first_name + " " + last_name;
    }

    string GetFullName(int year) {
        PersonItem &data = years[year];

        string first_name = data.firstName;
        string last_name = data.lastName;

        for (const auto&[key, value]: years) {
            if (key <= year) {
                if (!value.firstName.empty()) {
                    first_name = value.firstName;
                }

                if (!value.lastName.empty()) {
                    last_name = value.lastName;
                }
            }
        }

        bool is_empty_first_name = first_name.empty();
        bool is_empty_last_name = last_name.empty();

        if (is_empty_first_name && is_empty_last_name) {
            return "Incognito";
        }

        if (is_empty_first_name) {
            return last_name + " with unknown first name";
        }

        if (is_empty_last_name) {
            return first_name + " with unknown last name";
        }

        return first_name + " " + last_name;
    }

private:
    map<int, PersonItem> years;
};

int main() {
    Person person;

    person.ChangeFirstName(1900, "Eugene");
    person.ChangeLastName(1900, "Sokolov");
    person.ChangeLastName(1910, "Sokolov");
    person.ChangeFirstName(1920, "Evgeny");
    person.ChangeLastName(1930, "Sokolov");
    cout << person.GetFullNameWithHistory(1940) << endl;

    return 0;
}