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
