
//
// Created by Andrew Slesarenko on 15/01/2021.
//

#include "iostream"
#include "map"
#include "string"
#include "vector"

using namespace std;

void PrintAllBuses(const map<string, vector<string>>& bus_and_stops) {
    if (bus_and_stops.empty()) {
        cout << "No buses" << endl;
        return;
    }

    for (const auto& [bus, stops]: bus_and_stops) {
        cout << "Bus " << bus << ": ";

        for (const auto& stop: stops) {
            cout << stop << " ";
        }

        cout << endl;
    }

    cout << endl;
}

void PrintBusesForStop(const string& bus_stop, const map<string, vector<string>>& bus_and_stops) {
    vector<string> buses;

    for (const auto& [bus, stops]: bus_and_stops) {
        for (const auto& stop: stops) {
            if (stop == bus_stop) {
                buses.push_back(bus);
                continue;
            }
        }
    }

    if (buses.empty()) {
        cout << "No stop";
    } else {
        for (const auto& bus: buses) {
            cout << bus << " ";
        }
    }

    cout << endl;
}

void PrintStopsForBus(const string& bus_name, const map<string, vector<string>>& bus_and_stops) {
    map<string, vector<string>> stops_and_buses;

    if (bus_and_stops.count(bus_name) == 0) {
        cout << "No bus" << endl;
        return;
    }

    for (const auto& [bus, stops]: bus_and_stops) {
        if (bus != bus_name) {
            for (const auto &stop: stops) {
                stops_and_buses[stop].push_back(bus);
            }
        }
    }

    for (const auto& [stop, buses]: stops_and_buses) {
        cout << "Stop " << stop << ": ";

        if (buses.empty()) {
            cout << "no interchange" << endl;
        } else {
            for (const auto& bus: buses) {
                cout << bus << " ";
            }
        }


        cout << endl;
    }
}

void AddNewBusStops(const string& bus_name, const vector<string>& stops, map<string, vector<string>>& bus_and_stops) {
    for (const auto& stop: stops) {
        bus_and_stops[bus_name].push_back(stop);
    }
}

int main() {
    string NEW_BUS = "NEW_BUS";
    string BUSES_FOR_STOP = "BUSES_FOR_STOP";
    string STOPS_FOR_BUS = "STOPS_FOR_BUS";
    string ALL_BUSES = "ALL_BUSES";

    int operations_n;

    cin >> operations_n;

    map<string, vector<string>> bus_and_stops;

    for (int i = 0; i < operations_n; i++) {
        string command;

        cin >> command;

        if (command == ALL_BUSES) {
            PrintAllBuses(bus_and_stops);
        } else if (command == BUSES_FOR_STOP) {
            string bus_stop;

            cin >> bus_stop;

            PrintBusesForStop(bus_stop, bus_and_stops);
        } else if (command == STOPS_FOR_BUS) {
            string bus_name;

            cin >> bus_name;

            PrintStopsForBus(bus_name, bus_and_stops);
        } else if (command == NEW_BUS) {
            string bus_name;
            int stop_count;

            cin >> bus_name;
            cin >> stop_count;

            vector<string> stops;

            for (int z = 0; z < stop_count; z++) {
                string stop_name;

                cin >> stop_name;

                stops.push_back(stop_name);
            }

            AddNewBusStops(bus_name, stops, bus_and_stops);
        }
    }


    return 0;
}