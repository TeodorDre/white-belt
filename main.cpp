#include <cstdint>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

string COMMAND_DEL = "Del";
string COMMAND_FIND = "Find";
string COMMAND_ADD = "Add";
string COMMAND_PRINT = "Print";

//#region DATE

void RunCommand(stringstream &stream, string command) {
    stream << command << endl;
}

class Date {
public:
    Date(int c_year, int c_month, int c_day) {
        year = abs(c_year);
        if (c_month < 1 || c_month > 12) {
            throw logic_error("Month value is invalid: " + to_string(c_month));
        }
        month = c_month;
        if (c_day < 1 || c_day > 31) {
            throw logic_error("Day value is invalid: " + to_string(c_day));
        }
        day = c_day;
    }

    int GetYear() const {
        return year;
    }

    int GetMonth() const {
        return month;
    }

    int GetDay() const {
        return day;
    }

private:
    int year = 0;
    int month = 0;
    int day = 0;
};

bool operator<(const Date &d1, const Date &d2) {
    return vector<int>{d1.GetYear(), d1.GetMonth(), d1.GetDay()} <
           vector<int>{d2.GetYear(), d2.GetMonth(), d2.GetDay()};
}

ostream &operator<<(ostream &stream, const Date &date) {
    stream << setw(4) << setfill('0') << date.GetYear() << "-"
           << setw(2) << setfill('0') << date.GetMonth() << "-"
           << setw(2) << setfill('0') << date.GetDay();
    return stream;
}


void EnsureNextCharAndSkip(stringstream &stream, const string &date) {
    if (stream.peek() != '-') {
        throw logic_error("Wrong date format: " + date);
    }

    stream.ignore(1);
}

Date ParseDate(const string &date) {
    stringstream date_stream(date);

    int year, month, day;

    date_stream >> year;

    EnsureNextCharAndSkip(date_stream, date);

    date_stream >> month;

    EnsureNextCharAndSkip(date_stream, date);

    date_stream >> day;

    if (!date_stream.eof() || !date_stream) {
        throw logic_error("Wrong date format: " + date);
    }

    return {year, month, day};
}

//#endregion

class Database {
public:
    void Add(const Date &date, const string &event) {
        events[date].insert(event);
    }

    set<string> Find(const Date &date) const {
        if (events.count(date) > 0) {
            return events.at(date);
        } else {
            return {};
        }
    }

    bool Remove(const Date &date, const string &s) {
        if (events.count(date) > 0 && events[date].count(s) > 0) {
            events[date].erase(s);
            return true;
        }
        return false;
    }

    int Remove(const Date &date) {
        if (events.count(date) > 0) {
            const unsigned int event_count = events[date].size();
            events.erase(date);
            return event_count;
        }
        return 0;
    }

    void PrintAll() const {
        for (const auto &item : events) {
            for (const auto &event : item.second) {
                cout << item.first << " " << event << endl;
            }
        }
    }

private:
    map<Date, set<string>> events;
};

void ExecuteCommands(Database &db, istream &stream) {
    try {
        string command_line;

        while (getline(stream, command_line)) {
            // Добавляем строчку из стрима в стрим строки
            stringstream ss(command_line);
            // строка команды
            string command;
            ss >> command;

            // если пустая строка - пропускаем к следующей команде
            if (command.empty()) {
                continue;
            } else if (command == COMMAND_ADD) {
                string date, event;
                ss >> date >> event;
                // парсим дату из строки
                const Date d = ParseDate(date);
                db.Add(d, event);
            } else if (command == COMMAND_DEL) {
                string date, event;
                ss >> date;

                // если не конец строки - парсим название события
                if (!ss.eof()) {
                    ss >> event;
                }

                const Date d = ParseDate(date);
                // Если события не было - удаляем по дате всю дату
                if (event.empty()) {
                    cout << "Deleted " << db.Remove(d) << " events" << endl;
                } else {
                    // если было передано событие, удаляем событие, или говорим что удалять нечего
                    if (db.Remove(d, event)) {
                        cout << "Deleted successfully" << endl;
                    } else {
                        cout << "Event not found" << endl;
                    }
                }
            } else if (command == COMMAND_FIND) {
                string date;
                ss >> date;
                const Date d = ParseDate(date);
                for (const auto &event : db.Find(d)) {
                    cout << event << endl;
                }
            } else if (command == COMMAND_PRINT) {
                db.PrintAll();
            } else {
                throw logic_error("Unknown command: " + command);
            }
        }
    }
    catch (const exception &e) {
        cout << e.what() << endl;
    }
}

void RunProduction() {
    Database db;

    ExecuteCommands(db, cin);
}

void RunTest() {
    Database db;

    stringstream stream;

    // RunCommand(stream, "Add 1-1-1 event1");
    // RunCommand(stream, "Add qwerty qwerty");
    RunCommand(stream, "Add 0-1-2 event1");
    RunCommand(stream, "Add 1-2-3 event2");
    RunCommand(stream, "Find 0-1-2");
    // RunCommand(stream, "\t");
    RunCommand(stream, "Del 0-1-2");
    RunCommand(stream, "Print");
    RunCommand(stream, "Del 1-2-3 event2");
    RunCommand(stream, "Del 1-2-3 event2");
    // RunCommand(stream, "Add qwerty qwerty");
    // RunCommand(stream, "Add 1 1 1 event");

    ExecuteCommands(db, stream);
}

int main() {
    RunProduction();

    return 0;
}
