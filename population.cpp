#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int start, days;
    double percent;

    cout << "=== Population Growth ===\n";

    do {
        cout << "Enter starting population (>=2): ";
        cin >> start;
        cout << "Enter daily increase (%): ";
        cin >> percent;
        cout << "Enter number of days (>=1): ";
        cin >> days;

        if (start < 2 || percent < 0 || days < 1)
            cout << "Invalid input. Try again.\n\n";
    } while (start < 2 || percent < 0 || days < 1);

    double pop = start;
    double rate = percent / 100.0;

    cout << fixed << setprecision(2);
    cout << "\nDay\tPopulation\n";
    for (int day = 1; day <= days; ++day) {
        pop += pop * rate;
        cout << day << "\t" << pop << endl;
    }

    return 0;
}