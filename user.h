#pragma once
#include <string>
using namespace std;

struct User {
    string username;
    string password;
    string role;
};

void registerUser();
User loginUser();
bool isUsernameTaken(string username);
