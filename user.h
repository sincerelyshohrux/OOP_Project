#pragma once


#include <string>
using namespace std;

// user data structure
struct User {
    string username;
    string password;
    string role;     // "admin" or "customer"
};

// function declarations
void registerUser();
User loginUser();
bool isUsernameTaken(string username);










