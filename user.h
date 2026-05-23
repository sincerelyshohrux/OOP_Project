// Murtazayev Azizbek, U2510129

#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// ── BASE CLASS 
class User {
protected:
    string username;
    string password;
    string role;

public:
    // Constructor
    User(string u = "", string p = "", string r = "") {
        username = u;
        password = p;
        role = r;
    }

    // Getters 
    string getUsername() { return username; }
    string getPassword() { return password; }
    string getRole()     { return role; }

    // Virtual function - each role shows its own menu 
    virtual void showMenu() = 0;  // pure virtual 

    // Destructor 
    virtual ~User() {}
};

// ── CUSTOMER CLASS
class Customer : public User {
public:
    Customer(string u, string p) : User(u, p, "customer") {}

    void showMenu() override;  // polymorphism
};

// ── ADMIN CLASS 
class Admin : public User {
public:
    Admin(string u, string p) : User(u, p, "admin") {}

    void showMenu() override;  // polymorphism
};

// FREE FUNCTIONS 
bool isUsernameTaken(string username);
void registerUser();
User* loginUser();   // returns pointer to Customer or Admin







