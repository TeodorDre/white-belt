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

    std::string minimum = entries.front();

    for (const auto &entry : entries) {
        if (minimum > entry) {
            minimum = entry;
        }
    }

    return minimum;
}

int main() {
    std::string a;
    std::cin >> a;

    std::cout << getRelevantString(a) << std::endl;

    return 0;
}