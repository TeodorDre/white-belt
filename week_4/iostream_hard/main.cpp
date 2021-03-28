//
// Created by Andrew Slesarenko on 26/02/2021.
//

#include "iostream"
#include "fstream"
#include "string"
#include "vector"
#include "iomanip"

using namespace std;

int main() {
    ifstream input("input.txt");

    if (!input) {
        return 0;
    }

    string rows;
    string columns;

    vector<int> values;

    getline(input, rows, ' ');
    getline(input, columns);

    int int_rows = stoi(rows);
    int int_columns = stoi(columns);

    if (int_rows == 0) {
        return 0;
    }

    cout << setfill(' ');

    for (int row = 0; row < int_rows; row++) {
        for (int column = 0; column < int_columns; column++) {
            int value;

            input >> value;
            input.ignore(1);

            cout << right << setw(10);
            cout << value;

            if (column != int_columns - 1) {
                cout << " ";
            }
        }

        if (row != int_rows - 1) {
            cout << endl;
        }
    }

    return 0;
}
