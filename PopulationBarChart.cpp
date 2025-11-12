#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    cout << "=== Population Bar Chart ===\n";
    string filename;
    cout << "Enter data file: ";
    getline(cin, filename);

    ifstream fin(filename);
    if (!fin) {
        cout << "Error: file not found.\n";
        return 1;
    }

    vector<pair<int, double>> data;
    int year;
    double value;

    while (fin >> year >> value) {
        if (value >= 0)
            data.push_back({ year, value });
    }

    if (data.empty()) {
        cout << "No data found.\n";
        return 0;
    }

    double maxVal = 0;
    for (auto& x : data)
        if (x.second > maxVal) maxVal = x.second;

    double scale = (maxVal > 0) ? maxVal / 50.0 : 1;

    cout << fixed << setprecision(0);
    cout << "(Scale: 1 * = " << scale << " units)\n\n";

    for (auto& x : data) {
        cout << x.first << " | ";
        int stars = static_cast<int>(round(x.second / scale));
        for (int i = 0; i < stars; ++i)
            cout << '*';
        cout << endl;
    }
    return 0;
}