//
// Created by Andrew Slesarenko on 06/01/2021.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int main() {
    int operations_count;

    cin >> operations_count;
    vector<string> operations;

    for (int i = 0; i < operations_count; i++) {
        string operation_type;
        int operation_value;
        int worry_count = 0;
        int operations_size = operations.size();

        cin >> operation_type;

        if (operation_type == "WORRY_COUNT") {
            for (auto &item : operations) {
                if (item == "WORRY") {
                    worry_count++;
                }
            }

            cout << worry_count << endl;

            continue;
        }

        cin >> operation_value;

        if (operation_type == "WORRY") {
            operations[operation_value] = "WORRY";
        }

        if (operation_type == "QUIET") {
            operations[operation_value] = "QUIET";
        }

        if (operation_type == "COME" && operation_value > 0) {
            while (operation_value > 0) {
                operations.push_back("QUIET");
                operation_value--;
            }
        }

        if (operation_type == "COME" && operation_value < 0) {
            int resize_value = operations_size + operation_value;

            operations.resize(resize_value);
        }
    }

    return 0;
}

