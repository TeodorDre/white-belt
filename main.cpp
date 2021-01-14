
//
// Created by Andrew Slesarenko on 15/01/2021.
//

#include "iostream"
#include "map"
#include "string"
#include "vector"

using namespace std;

void PrintAllBuses() {

}

void PrintBusesForStop(const string& bus_stop) {

}

void PrintStopsForBus(const string& bus_name) {

}

void AddNewBusStops(const string& bus_name, const vector<string>& stops) {}

int main() {
    string NEW_BUSES = "NEW_BUSES";
    string BUSES_FOR_STOP = "BUSES_FOR_STOP";
    string STOPS_FOR_BUS = "STOPS_FOR_BUS";
    string ALL_BUSES = "ALL_BUSES";

    int operations_n;

    cin >> operations_n;

    for (int i = 0; i < operations_n; i++) {
        string command;

        if (command == ALL_BUSES) {
            PrintAllBuses();
        } else if (command == BUSES_FOR_STOP) {
            string bus_stop;

            cin >> bus_stop;

            PrintBusesForStop(bus_stop);
        } else if (command == STOPS_FOR_BUS) {
            string bus_name;

            cin >> bus_name;

            PrintStopsForBus(bus_name);
        } else if (command == NEW_BUSES) {
            string bus_name;
            int stop_count;

            cin >> bus_name;
            cin >> stop_count;

            vector<string> stops;

            for (int z = 0; i < stop_count; z++) {
                string stop_name;

                cin >> stop_name;

                stops.push_back(stop_name);
            }

            AddNewBusStops(bus_name, stops);
        }
    }


    return 0;
}