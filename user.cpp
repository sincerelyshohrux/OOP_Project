#include "user.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// check if username already exists in users.txt
bool isUsernameTaken(string username) {
    ifstream file("users.txt");
    string line;
    
    while (getline(file, line)) {
        stringstream ss(line);
        string saved;
        getline(ss, saved, ',');
        
        // if we find the same username return true
        if (saved == username) return true;
    }
    return false;
}

// register a new user and save to users.txt
void registerUser() {
    string username, password;
    
    cout << "\n=== REGISTER ===\n";
    cout << "Enter username: ";
    cin >> username;

    // dont allow duplicate usernames
    if (isUsernameTaken(username)) {
        cout << "Username already taken!\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    // save new user to file, everyone registers as customer
    ofstream file("users.txt", ios::app);
    file << username << "," << password << ",customer\n";
    file.close();
    
    cout << "Registration successful!\n";
}

// check username and password, return user if correct
User loginUser() {
    string username, password;
    
    cout << "\n=== LOGIN ===\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    ifstream file("users.txt");
    string line;
    
    while (getline(file, line)) {
        stringstream ss(line);
        string u, p, r;
        
        // split line by comma
        getline(ss, u, ',');
        getline(ss, p, ',');
        getline(ss, r, ',');
        
        // if both match, login success
        if (u == username && p == password) {
            cout << "Welcome, " << username << "!\n";
            return {username, password, r};
        }
    }
    
    cout << "Invalid username or password!\n";
    return {"", "", ""}; // empty user means login failed
}































