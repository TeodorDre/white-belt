#include <iostream>
#include <string>
#include <cmath>
#include <vector>

std::string getRelevantString(const std::string str) {
    std::string delim = " ";

    auto start = 0U;
    auto end = str.find(delim);

    std::vector<std::string> entries;

    while (end != std::string::npos) {
        std::string result = str.substr(start, end - start);
        entries.push_back(result);

        start = end + delim.length();
        end = str.find(delim, start);
    }

    std::string result = str.substr(start, end - start);
    entries.push_back(result);

    for (int i = 0; i <= entries.size(); i++) {
        std::cout << entries[i] << std::endl;
    }

    return str;
}

int main() {
    std::string a = "milk milkshake month";

    getRelevantString(a);

    return 0;
}