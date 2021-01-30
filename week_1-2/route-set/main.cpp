//
// Created by Andrew Slesarenko on 29/01/2021.
//

#include "iostream"
#include "map"
#include "set"

using namespace std;

void AddBusRoute(const set<string>& buses, map<set<string>, int>& routes) {
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

    map<set<string>, int> routes;

    cin >> operations_n;

    for (int i = 0; i < operations_n; i++) {
        int stop_count;
        cin >> stop_count;

        set<string> buses;

        for (int z = 0; z < stop_count; z++) {
            string bus;

            cin >> bus;

            buses.insert(bus);
        }

        AddBusRoute(buses, routes);
    }

    return 0;
}