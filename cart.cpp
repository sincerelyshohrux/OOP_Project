// Muminov Suxrobbek, U2510138

#include "cart.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Add product to cart
void addToCart(vector<CartItem>& cart) {
    int id, qty;
    cout << "Enter product ID: ";
    cin >> id;

    Product p = getProductById(id);
    if (p.getId() == -1) { cout << "Product not found!\n"; return; }

    cout << "How many? (available: " << p.getQuantity() << "): ";
    cin >> qty;

    if (qty > p.getQuantity()) { cout << "Not enough stock!\n"; return; }

    // If product already in cart, just increase quantity
    for (CartItem& item : cart) {
        if (item.getProduct().getId() == id) {
            item.addQuantity(qty);
            cout << p.getName() << " added to cart!\n";
            return;
        }
    }

    // Otherwise add as new item
    cart.push_back(CartItem(p, qty));
    cout << p.getName() << " added to cart!\n";
}

// Show all cart items
void showCart(vector<CartItem>& cart) {
    if (cart.empty()) { cout << "\nCart is empty!\n"; return; }

    cout << "\n=== YOUR CART ===\n";
    cout << left << setw(5) << "ID" << setw(20) << "Name"
         << setw(10) << "Price" << setw(6) << "Qty" << "Total\n";
    cout << string(50, '-') << "\n";

    for (CartItem& item : cart) {
        double sub = item.getProduct().getPrice() * item.getQuantity();
        cout << left
             << setw(5)  << item.getProduct().getId()
             << setw(20) << item.getProduct().getName()
             << setw(10) << item.getProduct().getPrice()
             << setw(6)  << item.getQuantity()
             << sub << "\n";
    }
    cout << string(50, '-') << "\n";
    cout << "TOTAL: $" << fixed << setprecision(2) << getTotal(cart) << "\n";
}

// Remove item from cart
void removeFromCart(vector<CartItem>& cart) {
    showCart(cart);
    if (cart.empty()) return;

    int id;
    cout << "Enter product ID to remove: ";
    cin >> id;

    for (int i = 0; i < (int)cart.size(); i++) {
        if (cart[i].getProduct().getId() == id) {
            cout << cart[i].getProduct().getName() << " removed!\n";
            cart.erase(cart.begin() + i);
            return;
        }
    }
    cout << "Product not found in cart!\n";
}

// Calculate total price
double getTotal(vector<CartItem>& cart) {
    double total = 0;
    for (CartItem& item : cart)
        total += item.getProduct().getPrice() * item.getQuantity();
    return total;
}