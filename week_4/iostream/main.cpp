//
// Created by Andrew Slesarenko on 26/02/2021.
//

#include "iostream"
#include "fstream"

using namespace std;

int main() {
    ifstream input2("input.txt");
    ofstream output("output.txt");
    string line2;

    if (input2) {
        while (getline(input2, line2)) {
            output << line2 << endl;
        }
    }

    return 0;
}
//
// Created by Andrew Slesarenko on 15/03/2021.
//

