#include <iostream>
#include <set>

using namespace std;

string AskTimeServer() {
    return {};
}

class TimeServer {
public:
    string GetCurrentTime() {
        try {
            string server_time = AskTimeServer();

            last_fetched_time = server_time;

            return server_time;
        } catch (const system_error &error) {
            return last_fetched_time;
        }
    }
private:
    string last_fetched_time = "00:00:00";
};

int main() {
    return 0;
}
