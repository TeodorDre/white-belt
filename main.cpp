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

class Date {
    Date(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }

public:
    int GetYear() {
        return this->year;
    }

    int GetMonth() {
        return this->month;
    }

    int GetDay() {
        return this->day;
    }

private:
    int year;
    int month;
    int day;
};

istream &operator>>(istream &stream, Date &date) {
    return stream;
}

ostream &operator<<(ostream &stream, Date &date) {
    return stream;
}

class Database {
public:
    void Add();

    void Remove();

    void Find();

    void PrintAll();

};

void PrintDatabase(Database &db) {
    db.PrintAll();
}

int main() {
    Database db;
    string command;

    while (getline(cin, command)) {
        string command_name;
        string date;
        string event_name;

        stringstream command_stream;
        command_stream << command;

        // Go to next line, if line is empty.
        if (command_stream.eof()) {
            continue;
        }

        command_stream >> command_name;
        command_stream.ignore(1);
        command_stream >> date;
        command_stream.ignore(1);
        command_stream >> event_name;

        if (command_name == COMMAND_ADD) {
            db.Add();
        } else if (command_name == COMMAND_DEL) {
            db.Remove();
        } else if (command_name == COMMAND_FIND) {
            db.Find();
        } else if (command_name == COMMAND_PRINT) {
            db.PrintAll();
        }


        cout << "Command: " << command_name << ". Date: " << date << ". Event: " << event_name << " ";
    }

    return 0;
}