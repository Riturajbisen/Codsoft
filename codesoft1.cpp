#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

using namespace std;

int main() {
    srand(time(0)); // seed the random number generator with current time

    int secretNumber = rand() % 100 + 1; // generates a random number between 1 and 100
    int guess;
    int attempts = 0;

    cout << "Welcome to the Guess the Number game!\n\n";

    do {
        cout << "Guess the number (between 1 and 100): ";
        cin >> guess;
        attempts++;

        if (guess > secretNumber) {
            cout << "Too high! Try again.\n";
        } else if (guess < secretNumber) {
            cout << "Too low! Try again.\n";
        } else {
            cout << "\nCongratulations! You've guessed the number (" << secretNumber << ") correctly!\n";
            cout << "Number of attempts: " << attempts << "\n";
        }
    } while (guess != secretNumber);

    return 0;
}
