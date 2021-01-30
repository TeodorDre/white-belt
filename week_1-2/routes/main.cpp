//
// Created by Andrew Slesarenko on 21/01/2021.
//

#include "iostream"
#include "map"
#include "vector"

using namespace std;

void AddBusRoute(const vector<string>& buses, map<vector<string>, int>& routes) {
    if (routes.count(buses) == 1) {
        cout << "Already exists for " << routes[buses] + 1 << endl;
    } else {
        int routes_size = routes.size();

        routes[buses] = routes_size;

        cout << "New bus " << routes.size() << endl;
    }
}

int main() {
    int operations_n;

    map<vector<string>, int> routes;

    cin >> operations_n;

    for (int i = 0; i < operations_n; i++) {
        int stop_count;
        cin >> stop_count;

        vector<string> buses;

        for (int z = 0; z < stop_count; z++) {
            string bus;

            cin >> bus;

            buses.push_back(bus);
        }

        AddBusRoute(buses, routes);
    }

    return 0;
}