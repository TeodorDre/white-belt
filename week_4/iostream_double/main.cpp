//
// Created by Andrew Slesarenko on 26/02/2021.
//

#include "iostream"
#include "fstream"
#include "vector"
#include "iomanip"

using namespace std;

int main() {
    ifstream input1("input.txt");

    string line1;

    vector<double> numbers;

    if (input1) {
        while (getline(input1, line1)) {
            double num = stod(line1);
            numbers.push_back(num);
        }
    }

    cout << fixed << setprecision(3);
    for (const double& num: numbers) {
        cout << num << endl;
    }

    return 0;
}
