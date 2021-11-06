//
// Created by Andrew Slesarenko on 25.09.2021.
//

#include "iostream"
#include "sstream"
#include "map"
#include "set"
#include "vector"
#include "algorithm"

using namespace std;

string COMMAND_DEL = "Del";
string COMMAND_FIND = "Find";
string COMMAND_ADD = "Add";
string COMMAND_PRINT = "Print";

//#region DATE

class Date {
public:
    Date(int y, int m, int d) {
        Date::Validate(y, m, d);

        year = y;
        month = m;
        day = d;
    }

    Date() {}

    void Init(int y, int m, int d) {
        Date::Validate(y, m, d);

        year = y;
        month = m;
        day = d;
    }

    int GetYear() const {
        return this->year;
    }

    int GetMonth() const {
        return this->month;
    }

    int GetDay() const {
        return this->day;
    }

    string GetFullDate() const {
        return to_string(GetYear()) + to_string(GetMonth()) + to_string(GetDay());
    }

    bool operator<(const Date &date) const {
        return GetFullDate() < date.GetFullDate();
    }

    void static Validate(int y, int m, int d);

private:
    int year{};
    int month{};
    int day{};
};

istream &operator>>(istream &stream, Date &date) {
    int y, m, d;

    if (!(stream >> y)) {
        return stream;
    }

    if (stream.get() == '-') {
        stream.unget();
    }

    if (!(stream.ignore(1))) {
        return stream;
    }

    if (!(stream >> m)) {
        return stream;
    }

    if (stream.get() == '-') {
        stream.unget();
    }

    if (!(stream.ignore(1))) {
        return stream;
    }

    if (!(stream >> d)) {
        return stream;
    }

    date.Init(y, m, d);

    return stream;
}

ostream &operator<<(ostream &stream, const Date &date) {
    stream << date.GetYear() << "-" << date.GetMonth() << "-" << date.GetDay();

    return stream;
}

void Date::Validate(int y, int m, int d) {
    bool is_invalid_month = m <= 0 || m >= 13;

    if (is_invalid_month) {
        throw invalid_argument("Month value is invalid: " + to_string(m));
    }

    bool is_invalid_day = d <= 0 || d >= 32;

    if (is_invalid_day) {
        throw invalid_argument("Day value is invalid: " + to_string(d));
    }
}

//#endregion

//#region DATABASE

class Database {
private:
    map<Date, set<string>> records;

public:
    void Add(const Date &date, string &event);

    void Remove(const Date &date, string &event);

    void Find(const Date &date);

    void PrintAll() const;

};

void Database::Add(const Date &date, string &event) {
    if (records.count(date) == 0) {
        records[date] = {};
    }

    auto event_list = records.find(date);

    if (event_list->second.count(event) == 0) {
        event_list->second.insert(event);
    }
}

void Database::Remove(const Date &date, string &event) {
    bool has_event = !event.empty();

    if (has_event) {
        if (records.count(date) != 0) {
            auto record_date = records.find(date);

            if (record_date->second.count(event) != 0) {
                record_date->second.erase(event);
                cout << "Deleted successfully" << endl;
            } else {
                cout << "Event not found" << endl;
            }
        } else {
            cout << "Event not found" << endl;
        }
    } else {
        if (records.count(date) != 0) {
            auto record_date = records.find(date);

            int record_events_size = record_date->second.size();

            record_date->second.clear();
            cout << "Deleted " << record_events_size << " events" << endl;
            return;
        }

        cout << "Event not found" << endl;
    }
}

void Database::Find(const Date &date) {
    auto record_date = records.find(date);

    if (records.empty()) {
        return;
    }

    auto events_set = record_date->second;

    for (const auto &event: events_set) {
        cout << event << endl;
    }
}

void Database::PrintAll() const {
    for (const auto &record: records) {
        const Date &date = record.first;
        auto &events_set = record.second;

        if (events_set.empty()) {
            continue;
        }

        for (const string &event: events_set) {
            cout << date << " " << event << endl;
        }
    }
}

//#endregion

void RunInputStreamTests(Database &db, istream &stream) {
    string command;

    while (getline(stream, command)) {
        string command_name_raw;
        string date_raw;
        string event_name_raw;

        stringstream command_stream;
        command_stream << command;

        // Go to next line, if line is empty.
        if (command_stream.eof()) {
            continue;
        }

        command_stream >> command_name_raw;
        command_stream.ignore(1);

        Date date;

        try {
            command_stream >> date;
        } catch (const invalid_argument &error) {
            cout << error.what();
        }

        command_stream.ignore(1);
        command_stream >> event_name_raw;

        if (command_name_raw == COMMAND_ADD) {
            db.Add(date, event_name_raw);
        } else if (command_name_raw == COMMAND_DEL) {
            db.Remove(date, event_name_raw);
        } else if (command_name_raw == COMMAND_FIND) {
            db.Find(date);
        } else if (command_name_raw == COMMAND_PRINT) {
            db.PrintAll();
        } else {
            cout << "Unknown command: " << command_name_raw << endl;
            continue;
        }
    }
}

void RunCommand(stringstream &stream, string command) {
    stream << command << endl;
}

int main() {
    Database db;

    stringstream stream;
    RunCommand(stream, "Add 0-1-2 event1");
    RunCommand(stream, "Add 1-2-3 event2");
    RunCommand(stream, "Find 0-1-2");
    RunCommand(stream, "Del 0-1-2");
    RunCommand(stream, "Print");
    RunCommand(stream, "Del 1-2-3 event2");
    RunCommand(stream, "Del 1-2-3 event2");

    RunInputStreamTests(db, stream);

    return 0;
}