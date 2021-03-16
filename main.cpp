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

    if (input) {
        string rows;
        string columns;

        vector<char> values;

        getline(input, rows, ' ');
        getline(input, columns);

        string curr_value;

        while (getline(input, curr_value)) {
            for (const char &i: curr_value) {
                if (i != ',') {
                    values.push_back(i);
                }
            }
        }

        int curr_index = 0;

        vector<vector<char>> rows_values(stoi(rows));

        for (const auto &i: values) {
            rows_values[curr_index].push_back(i);

            if (rows_values[curr_index].size() == stoi(columns)) {
                curr_index += 1;
            }
        }

        int curr_row_index = 0;

        for (const vector<char>& row_value: rows_values) {
            int value_index = 0;

            for (const auto &i: row_value) {
                cout << setw(10);

                value_index += 1;
                cout << " " << i;

                if (row_value.size() != value_index) {
                    cout << " ";
                }
            }

            curr_row_index += 1;

            if (rows_values.size() != curr_row_index) {
                cout << endl;
            }
        }
    }

    return 0;
}
