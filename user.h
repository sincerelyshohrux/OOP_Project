// Murtazayev Azizbek, U2510129

#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// ── BASE CLASS (Lecture 1, 2) ──────────────────────────────
class User {
protected:
    string username;
    string password;
    string role;

public:
    // Constructor (Lecture 2)
    User(string u = "", string p = "", string r = "") {
        username = u;
        password = p;
        role = r;
    }

    // Getters (Lecture 2)
    string getUsername() { return username; }
    string getPassword() { return password; }
    string getRole()     { return role; }

    // Virtual function - each role shows its own menu (Lecture 7)
    virtual void showMenu() = 0;  // pure virtual (Lecture 9)

    // Destructor (Lecture 2)
    virtual ~User() {}
};

// ── CUSTOMER CLASS (Lecture 6 - Inheritance) ───────────────
class Customer : public User {
public:
    Customer(string u, string p) : User(u, p, "customer") {}

    void showMenu() override;  // Lecture 7 - polymorphism
};

// ── ADMIN CLASS (Lecture 6 - Inheritance) ──────────────────
class Admin : public User {
public:
    Admin(string u, string p) : User(u, p, "admin") {}

    void showMenu() override;  // Lecture 7 - polymorphism
};

// ── FREE FUNCTIONS ─────────────────────────────────────────
bool isUsernameTaken(string username);
void registerUser();
User* loginUser();   // returns pointer to Customer or Admin







