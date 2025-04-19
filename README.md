# Slot Machine Game

A simple slot machine game utilizing random number generators and vectors.

## Purpose

The purpose is to simulate a game of a simple slot machine utilizing the vector library and random number generators.

## How to Use

```c++
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
