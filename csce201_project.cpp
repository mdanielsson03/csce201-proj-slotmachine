// Madeleine Danielsson & Amar Otgonbayar
// Date: 4/20/2025
// CSCE 201 Project
// Simple Slot Machine Simulator

#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    srand(time(NULL));

    vector<string> symbols = { "Orange", "Diamond", "Cherry", "Melon", "Bell", "Grape", "Seven" };
    const int tiles = 3;

    double balance = 100.0;

    cout << "\t\tC++ Slot Machine" << endl;
    
    while (balance > 0) {
        cout << "Current balance: $" << balance << endl;

        double bet;
        cout << "Enter your bet: ";
        cin >> bet;

        if (cin.fail() || bet <= 0) {
            cout << "Invalid input: Your bet cannot be less than zero." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (bet > balance) {
            cout << "Your bet exceeds your current balance. Please enter again." << endl;
            continue;
        }

        balance -= bet;

        // Spin the wheel
        vector<string> reels(tiles);
        cout << "\nSpinning..." << endl;
        for (int i = 0; i < tiles; i++) {
            int randomIndex = rand() % symbols.size();
            reels[i] = symbols[randomIndex];
        }

        // Display reels
        cout << "----------------------------" << endl;
        cout << reels[0] << " | " << reels[1] << " | " << reels[2] << endl;
        cout << "----------------------------" << endl;

        // Check winning combinations
        double winnings = 0;

        // Three of a kind
        if (reels[0] == reels[1] && reels[1] == reels[2]) {
            cout << "Congratulations! Three of a kind!" << endl;
            if (reels[0] == "Orange") {
                winnings = bet * 5;
                cout << "You won $" << fixed << setprecision(2) << winnings << "!" << endl;
            }
            else if (reels[0] == "Diamond") {
                winnings = bet * 10;
                cout << "You won $" << fixed << setprecision(2) << winnings << "!" << endl;
            }
            else if (reels[0] == "Cherry") {
                winnings = bet * 15;
                cout << "You won $" << fixed << setprecision(2) << winnings << "!" << endl;
            }
            else if (reels[0] == "Melon") {
                winnings = bet * 20;
                cout << "You won $" << fixed << setprecision(2) << winnings << "!" << endl;
            }
            else if (reels[0] == "Bell") {
                winnings = bet * 50;
                cout << "You won $" << fixed << setprecision(2) << winnings << "!" << endl;
            }
            else if (reels[0] == "Grape") {
                winnings = bet * 100;
                cout << "You won $" << fixed << setprecision(2) << winnings << "!" << endl;
            }
            else if (reels[0] == "Seven") {
                winnings = bet * 200;
                cout << "JACKPOT! You won $" << fixed << setprecision(2) << winnings << "!" << endl;
            }
        }
        // Two of a kind
        else if (reels[0] == reels[1] || reels[1] == reels[2] || reels[0] == reels[2]) {
            cout << "Nice! Two of a kind!" << endl;
            winnings = bet * 2;
            cout << "You won $" << fixed << setprecision(2) << winnings << "!" << endl;
        }
        // Losing message
        else {
            cout << "No winning combination found." << endl;
        }

        // Add winnings to balance
        balance += winnings;

        char choice;
        cout << endl;
        cout << "Would you like to play again? ";
        cin >> choice;

        if (choice == 'y') {
            continue;
        }
        else {
            break;
        }
    }

    cout << "Final balance: $" << balance << endl;

    return 0;
}
