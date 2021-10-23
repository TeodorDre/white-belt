//
// Created by Andrew Slesarenko on 25.09.2021.
//

#include "iostream"
#include "sstream"

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
    stream << date.GetYear() << " " << date.GetMonth() << " " << date.GetDay();

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
public:
    void Add();

    void Remove();

    void Find();

    void PrintAll() const;

};

void Database::Add() {
    //
}

void Database::Remove() {
    //
}

void Database::Find() {
    //
}

void Database::PrintAll() const {
    //
}

//#endregion

void PrintDatabase(Database const &db) {
    db.PrintAll();
}

void RunTests(Database &db) {
    string command;

    while (getline(cin, command)) {
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
            db.Add();
        } else if (command_name_raw == COMMAND_DEL) {
            db.Remove();
        } else if (command_name_raw == COMMAND_FIND) {
            db.Find();
        } else if (command_name_raw == COMMAND_PRINT) {
            db.PrintAll();
        } else {
            cout << "Unknown command: " << command_name_raw << endl;
            continue;
        }
    }
}

int main() {
    Database db;

    RunTests(db);

    return 0;
}