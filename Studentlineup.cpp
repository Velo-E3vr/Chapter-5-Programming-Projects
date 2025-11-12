#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string trim(const string& s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end = s.find_last_not_of(" \t\r\n");
    if (start == string::npos) return "";
    return s.substr(start, end - start + 1);
}

int main() {
    cout << "=== Student Lineup ===\n";
    string filename;
    cout << "Enter input file name: ";
    getline(cin, filename);  // Example input: Studentlineup.txt

    ifstream fin(filename);
    if (!fin) {
        cout << "Error: could not open file.\n";
        return 1;
    }

    string first, last, name;
    int count = 0;

    while (getline(fin, name)) {
        name = trim(name);
        if (name.empty()) continue;

        if (count == 0)
            first = last = name;
        else {
            if (name < first) first = name;
            if (name > last)  last = name;
        }
        count++;
    }

    if (count == 0)
        cout << "No names found.\n";
    else {
        cout << "Class size: " << count << endl;
        cout << "First: " << first << endl;
        cout << "Last:  " << last << endl;
    }

    return 0;
}