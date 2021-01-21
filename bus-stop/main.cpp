
//
// Created by Andrew Slesarenko on 15/01/2021.
//

#include "iostream"
#include "map"
#include "string"
#include "vector"
#include <algorithm>

using namespace std;

int getIndex(vector<string>& v, string K) {
    auto it = find(v.begin(), v.end(), K);

    // If element was found
    if (it != v.end()) {

        // calculating the index
        // of K
        int index = it - v.begin();
        return index;
    } else {
        // If the element is not
        // present in the vector
        return -1;
    }
}

void PrintAllBuses(const map<string, vector<string>> &bus_and_stops) {
    if (bus_and_stops.empty()) {
        cout << "No buses" << endl;
        return;
    }

    for (const auto&[bus, stops]: bus_and_stops) {
        cout << "Bus " << bus << ": ";

        for (const auto &stop: stops) {
            cout << stop << " ";
        }

        cout << endl;
    }

    cout << endl;
}

void PrintBusesForStop(const string &bus_stop, const map<string, vector<string>> &bus_and_stops, vector<string>& all_buses) {
    vector<string> buses;

    for (const auto&[bus, stops]: bus_and_stops) {
        for (const auto &stop: stops) {
            if (stop == bus_stop) {
                buses.push_back(bus);
                continue;
            }
        }
    }

    if (buses.empty()) {
        cout << "No stop";
    } else {
        int max_count = 0;

        for (const auto &bus: all_buses) {
            for (const auto& current_bus: buses) {
                if (std::find(all_buses.begin(), all_buses.end(), current_bus) != all_buses.end()) {
                    cout << current_bus << " ";
                    max_count++;
                }
            }

            if (max_count >= buses.size()) {
                break;
            }
        }
    }

    cout << endl;
}

void
PrintStopsForBus(const string &bus_name, const map<string, vector<string>> &bus_and_stops, vector<string> &all_stops) {
    map<string, vector<string>> stops_and_buses;

    if (bus_and_stops.count(bus_name) == 0) {
        cout << "No bus" << endl;
        return;
    }

    for (const auto&[bus, stops]: bus_and_stops) {
        if (bus == bus_name) {
            for (const auto &stop: stops) {
                for (const auto&[bus1, stops1]: bus_and_stops) {
                    for (const auto &stop1: stops1) {
                        if (stop1 == stop) {
                            vector<string> &v = stops_and_buses[stop];

                            if (std::find(v.begin(), v.end(), bus1) != v.end()) {
                                //
                            } else {
                                if (bus1 != bus_name) {
                                    stops_and_buses[stop].push_back(bus1);
                                }
                            }
                        }
                    }
                }

                if (stops_and_buses[stop].empty()) {
                    stops_and_buses[stop] = {"none"};
                }
            }
        }
    }

    vector<string> valid_stops;

    for (const auto &stop: all_stops) {
        vector<string> &buses = stops_and_buses[stop];

        if (buses.size() == 1) {
            string &res = buses[0];

            if (res == "none") {
                cout << "Stop " << stop << ": " << "no interchange" << endl;
            } else {
                cout << "Stop " << stop << ": " << res << endl;
            }

            continue;;
        }

        if (!buses.empty()) {
            cout << "Stop " << stop << ": ";

            for (const auto &bus: buses) {
                cout << bus << " ";
            }

            cout << endl;
        }
    }
}

void AddNewBusStops(const string &bus_name, const vector<string> &stops, map<string, vector<string>> &bus_and_stops) {
    for (const auto &stop: stops) {
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
    vector<string> all_stops;
    vector<string> all_buses;

    for (int i = 0; i < operations_n; i++) {
        string command;

        cin >> command;

        if (command == ALL_BUSES) {
            PrintAllBuses(bus_and_stops);
        } else if (command == BUSES_FOR_STOP) {
            string bus_stop;

            cin >> bus_stop;

            PrintBusesForStop(bus_stop, bus_and_stops, all_buses);
        } else if (command == STOPS_FOR_BUS) {
            string bus_name;

            cin >> bus_name;

            PrintStopsForBus(bus_name, bus_and_stops, all_stops);
        } else if (command == NEW_BUS) {
            string bus_name;
            int stop_count;

            cin >> bus_name;

            if (std::find(all_buses.begin(), all_buses.end(), bus_name) != all_buses.end()) {
                int index = getIndex(all_buses, bus_name);
                all_buses.erase(all_buses.begin() + index);
            }

            all_buses.push_back(bus_name);

            cin >> stop_count;

            vector<string> stops;

            for (int z = 0; z < stop_count; z++) {
                string stop_name;
                cin >> stop_name;

                if (std::find(all_stops.begin(), all_stops.end(), stop_name) != all_stops.end()) {
                    int index = getIndex(all_stops, stop_name);
                    all_stops.erase(all_stops.begin() + index);
                }

                all_stops.push_back(stop_name);
                stops.push_back(stop_name);
            }

            AddNewBusStops(bus_name, stops, bus_and_stops);
        }
    }

    return 0;
}