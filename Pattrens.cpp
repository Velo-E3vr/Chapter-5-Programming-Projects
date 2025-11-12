#include <iostream>
using namespace std;

void printChars(char c, int count) {
    for (int i = 0; i < count; ++i)
        cout << c;
}

int main() {
    int n;
    do {
        cout << "Enter size (>=1): ";
        cin >> n;
        if (n < 1) cout << "Invalid. Try again.\n";
    } while (n < 1);

    cout << "\nA)\n";
    for (int r = 1; r <= n; ++r) { printChars('*', r); cout << endl; }

    cout << "\nB)\n";
    for (int r = n; r >= 1; --r) { printChars('*', r); cout << endl; }

    cout << "\nC)\n";
    for (int r = 1; r <= n; ++r) { printChars(' ', n - r); printChars('*', r); cout << endl; }

    cout << "\nD)\n";
    for (int r = n; r >= 1; --r) { printChars(' ', n - r); printChars('*', r); cout << endl; }

    return 0;
}