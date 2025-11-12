#include <iostream>
#include <random>
#include <string>
using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 100);
    int secret = dist(gen);
    int attempts = 0;
    string input;

    cout << "Guess a number between 1 and 100 (type 'q' to quit)\n";

    while (true) {
        cout << "Enter guess: ";
        getline(cin, input);

        if (input == "q" || input == "Q") {
            cout << "Game over. The number was " << secret << ".\n";
            break;
        }

        try {
            int guess = stoi(input);
            if (guess < 1 || guess > 100) {
                cout << "Please enter a number between 1 and 100.\n";
                continue;
            }

            attempts++;
            if (guess < secret)
                cout << "Too low.\n";
            else if (guess > secret)
                cout << "Too high.\n";
            else {
                cout << "Correct! You guessed it in " << attempts << " tries.\n";
                break;
            }
        }
        catch (...) {
            cout << "Invalid input. Enter a number or 'q'.\n";
        }
    }
    return 0;
}
