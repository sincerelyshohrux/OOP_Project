#include "cart.h"
#include <iostream>
#include <iomanip>
using namespace std;

void addToCart(vector<CartItem>& cart) {
    int id, qty;
    cout << "Enter product ID: ";
    cin >> id;

    Product p = getProductById(id);
    if (p.id == -1) { cout << "Product not found!\n"; return; }

    cout << "How many? (available: " << p.quantity << "): ";
    cin >> qty;

    if (qty > p.quantity) { cout << "Not enough stock!\n"; return; }

    for (CartItem& item : cart) {
        if (item.product.id == id) {
            item.quantity += qty;
            cout << p.name << " added to cart!\n";
            return;
        }
    }
    cart.push_back({p, qty});
    cout << p.name << " added to cart!\n";
}

void showCart(vector<CartItem>& cart) {
    if (cart.empty()) { cout << "\nCart is empty!\n"; return; }

    cout << "\n=== YOUR CART ===\n";
    cout << left << setw(5) << "ID" << setw(20) << "Name"
         << setw(10) << "Price" << setw(6) << "Qty" << "Total\n";
    cout << string(50, '-') << "\n";

    for (CartItem& item : cart) {
        double sub = item.product.price * item.quantity;
        cout << left << setw(5) << item.product.id
             << setw(20) << item.product.name
             << setw(10) << item.product.price
             << setw(6)  << item.quantity
             << sub << "\n";
    }
    cout << string(50, '-') << "\n";
    cout << "TOTAL: $" << fixed << setprecision(2) << getTotal(cart) << "\n";
}

void removeFromCart(vector<CartItem>& cart) {
    showCart(cart);
    if (cart.empty()) return;
    int id;
    cout << "Enter product ID to remove: ";
    cin >> id;
    for (int i = 0; i < (int)cart.size(); i++) {
        if (cart[i].product.id == id) {
            cout << cart[i].product.name << " removed!\n";
            cart.erase(cart.begin() + i);
            return;
        }
    }
    cout << "Product not found in cart!\n";
}

double getTotal(vector<CartItem>& cart) {
    double total = 0;
    for (CartItem& item : cart)
        total += item.product.price * item.quantity;
    return total;
}
