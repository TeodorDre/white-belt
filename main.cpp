// Created by Andrew Slesarenko on 06/01/2021.

#include "iostream"
#include "vector"

using namespace std;

void AddTask(const int &day_number, const string& task_name, vector<vector<string>>& timetable) {
    timetable[day_number - 1].push_back(task_name);
}

void DumpDay(const int &day_number, vector<vector<string>>& timetable) {
    const vector<string>& day_tasks = timetable[day_number - 1];

    if (!day_tasks.empty()) {
        cout << day_tasks.size() << " ";

        for (const auto& i : day_tasks) {
            cout << i << " ";
        }
    } else {
        cout << 0 << endl;
    }
}

void OpenNextMonth(int& current_month, const vector<int>& days_in_month, vector<vector<string>>& timetable) {
    int current_month_days = days_in_month[current_month];
    int next_month_days = days_in_month[current_month + 1];

    if (next_month_days > current_month_days) {
        timetable.resize(current_month_days, {});
    } else if (current_month_days > next_month_days) {
        vector<string> last_day = timetable.back();

        int rest_days = current_month_days - next_month_days;

        int timetable_size = timetable.size();

        for (int i = rest_days; i > 1; i--) {
            int index = timetable_size - i;
            vector<string> new_last_day = timetable[index];

            last_day.insert(end(last_day), begin(new_last_day), end(new_last_day));
        }

        timetable.resize(next_month_days);
        timetable[next_month_days - 1] = last_day;
    }

    current_month += 1;

    if (current_month == 12) {
        current_month = 0;
    }
}

int main() {
    int operations_n;
    cin >> operations_n;

    int current_month = 0;

    vector<int> days_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};

    vector<vector<string>> timetable(days_in_month[current_month]);

    for (int i = 0; i < operations_n; i++) {
        string operation_type;
        int day_number;

        cin >> operation_type;

        if (operation_type == "NEXT") {
            OpenNextMonth(current_month, days_in_month, timetable);
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