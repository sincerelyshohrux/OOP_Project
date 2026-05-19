#include <iostream>
#include "user.h"
#include "product.h"
#include "cart.h"
#include "order.h"
#include "admin.h"
using namespace std;

void customerMenu(User currentUser) {
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
        else if (choice == 6) checkout(cart, currentUser.username);
        else if (choice == 0) break;
        else cout << "Invalid choice!\n";
    }
}

void adminMenu() {
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

int main() {
    int choice;
    while (true) {
        cout << "\n=== VirtualMart ===\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "0. Exit\n";
        cout << "Select: ";
        cin >> choice;

        if (choice == 0) { cout << "Goodbye!\n"; break; }
        else if (choice == 1) registerUser();
        else if (choice == 2) {
            User currentUser = loginUser();
            if (currentUser.username == "") continue;
            if (currentUser.role == "admin") adminMenu();
            else customerMenu(currentUser);
        }
        else cout << "Invalid choice!\n";
    }
    return 0;
}
