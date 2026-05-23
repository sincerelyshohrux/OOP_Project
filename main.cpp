// Saydinabiyev Saidazizxon , U2510103
// Ahmadjonov Farruhbek, U2510119
// Murtazayev Azizbek, U2510129
// Maxamatjonov Shohruxbek, U2510135
// Muminov Suxrobbek, U2510138
// Section 003

#include <iostream>
#include "user.h"
using namespace std;

int main() {
    int choice;

    while (true) {
        cout << "\n=== VirtualMart ===\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "0. Exit\n";
        cout << "Select: ";
        cin >> choice;

        if (choice == 0) {
            cout << "Goodbye!\n";
            break;
        }
        else if (choice == 1) {
            registerUser();
        }
        else if (choice == 2) {
            // loginUser returns Customer* or Admin* (Lecture 6, 7)
            User* user = loginUser();

            if (user == nullptr) continue;

            // Polymorphism - calls correct showMenu() (Lecture 7)
            user->showMenu();

            // Free memory (Lecture 2)
            delete user;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}















