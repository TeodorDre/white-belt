//
// Created by Andrew Slesarenko on 06/01/2021.
//

#include "iostream"
#include "vector"

using namespace std;

void AddTask(const int &day_number, const string& task_name, vector<vector<string>>& timetable) {
    timetable[day_number].push_back(task_name);
}

void DumpDay(const int &day_number, vector<vector<string>>& timetable) {
    const vector<string>& day_tasks = timetable[day_number];

    cout << day_number << " ";

    for (const auto& i : day_tasks) {
        cout << i << " ";
    }
}

void OpenNextMonth(vector<vector<string>>& timetable) {

}

int main() {
    int operations_n;
    cin >> operations_n;

    vector<vector<string>> timetable(31);

    for (int i = 0; i < operations_n; i++) {
        string operation_type;
        int day_number;

        cin >> operation_type;

        if (operation_type == "NEXT") {
            OpenNextMonth(timetable);
        }

        if (operation_type == "DUMP" || operation_type == "ADD") {
            cin >> day_number;
        }

        if (operation_type == "DUMP") {
            DumpDay(day_number, timetable);
        }

        if (operation_type == "ADD") {
            string task_name;
            cin >> task_name;

            AddTask(day_number, task_name, timetable);
        }
    }

    return 0;
}