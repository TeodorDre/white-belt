//
// Created by Andrew Slesarenko on 05/01/2021.
//

#include "iostream"
#include "vector"

using namespace std;

int main() {
    int days_count;
    cin >> days_count;

    int total_degrees = 0;
    vector<int> day_degrees;

    while (days_count > 0) {
        int degree;
        cin >> degree;

        total_degrees += degree;
        day_degrees.push_back(degree);

        days_count--;
    }

    int day_degrees_size = day_degrees.size();
    int average_degree = total_degrees / day_degrees_size;

    vector<int>days_average_indexes;

    for (int i = 0; i < day_degrees_size; i++) {
        int& entry = day_degrees[i];

        if (entry > average_degree) {
            days_average_indexes.push_back(i);
        }
    }

    cout << days_average_indexes.size() << endl;

    for (auto& i : days_average_indexes) {
        cout << i << " ";
    }

    return 0;
}