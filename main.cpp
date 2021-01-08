//
// Created by Andrew Slesarenko on 06/01/2021.
//

#include "iostream"
#include "vector"

using namespace std;

vector<int> days_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void AddTask(const int &day_number, const string& task_name, vector<vector<string>> timetable) {
    timetable[day_number].push_back(task_name);
}

int main() {
    int operations_n;
    cin >> operations_n;

    vector<vector<string>> timetable(31);

    for (int i = 0; i < operations_n; i++) {
        string operation_type;
        string task_name;

        int day_number;

        cin >> operation_type;
        cin >> day_number;
        cin >> task_name;

        if (operation_type == "ADD") {
            AddTask(day_number, task_name, timetable);
        }
    }

    return 0;
}