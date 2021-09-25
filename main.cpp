//
// Created by Andrew Slesarenko on 25.09.2021.
//

class Date {
    Date(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }

private:
    int year;
    int month;
    int day;
};

class Database {
public:
    void Add();

    void Remove();

    void RemoveMany();

    void Find();

    void PrintAll();

};

int main() {
    return 0;
}