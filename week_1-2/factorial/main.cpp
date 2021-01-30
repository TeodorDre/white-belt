#include "iostream"

using namespace std;

int Factorial(int n) {
    if (n <= 0) {
        return 1;
    } else {
        return Factorial(n - 1) * n;
    }
}

int main() {
    int num;

    cin >> num;

    cout << Factorial(num);

    return 0;
}

