// Murtazayev Azizbek, U2510129
#include "user.h"
#include "product.h"
#include "cart.h"
#include "order.h"
#include "admin.h"
using namespace std;

// Check if username already exists in users.txt
bool isUsernameTaken(string username) {
    ifstream file("users.txt");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string saved;
        getline(ss, saved, ',');
        if (saved == username) return true;
    }
    return false;
}

// Register new user and save to users.txt
void registerUser() {
    string username, password;
    cout << "\n=== REGISTER ===\n";
    cout << "Enter username: ";
    cin >> username;

    if (isUsernameTaken(username)) {
        cout << "Username already taken!\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);
    file << username << "," << password << ",customer\n";
    file.close();
    cout << "Registration successful!\n";
}

// Login - returns Customer or Admin object (Lecture 6, 7)
User* loginUser() {
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
        getline(ss, u, ',');
        getline(ss, p, ',');
        getline(ss, r, ',');

        if (u == username && p == password) {
            cout << "Welcome, " << username << "!\n";

            // Return correct object based on role (Lecture 6)
            if (r == "admin") return new Admin(u, p);
            else              return new Customer(u, p);
        }
    }

    cout << "Invalid username or password!\n";
    return nullptr;
}

// Customer menu (Lecture 7 - polymorphism)
void Customer::showMenu() {
    vector<CartItem> cart;
    int choice;

    while (true) {
        cout << "\n=== CUSTOMER MENU ===\n";
        cout << "1. Phones\n";
        cout << "2. Notebooks\n";
        cout << "3. Cars\n";
        cout << "4. View cart\n";
        cout << "5. Remove from cart\n";
        cout << "6. Checkout\n";
        cout << "0. Logout\n";
        cout << "Select: ";
        cin >> choice;

        if (choice == 1) {
            showByCategory("phone");
            cout << "Add to cart? (1-Yes, 0-No): ";
            int add; cin >> add;
            if (add == 1) addToCart(cart);
        }
        else if (choice == 2) {
            showByCategory("notebook");
            cout << "Add to cart? (1-Yes, 0-No): ";
            int add; cin >> add;
            if (add == 1) addToCart(cart);
        }
        else if (choice == 3) {
            showByCategory("car");
            cout << "Add to cart? (1-Yes, 0-No): ";
            int add; cin >> add;
            if (add == 1) addToCart(cart);
        }
        else if (choice == 4) showCart(cart);
        else if (choice == 5) removeFromCart(cart);
        else if (choice == 6) checkout(cart, getUsername());
        else if (choice == 0) break;
        else cout << "Invalid choice!\n";
    }
}

// Admin menu (Lecture 7 - polymorphism)
void Admin::showMenu() {
    int choice;
    while (true) {
        cout << "\n=== ADMIN MENU ===\n";
        cout << "1. Add product\n";
        cout << "2. View all products\n";
        cout << "3. Delete product\n";
        cout << "4. Edit product\n";
        cout << "5. View all orders\n";
        cout << "0. Logout\n";
        cout << "Select: ";
        cin >> choice;

        if      (choice == 1) addProduct();
        else if (choice == 2) showAllProducts();
        else if (choice == 3) deleteProduct();
        else if (choice == 4) editProduct();
        else if (choice == 5) viewOrders();
        else if (choice == 0) break;
        else cout << "Invalid choice!\n";
    }
}





























