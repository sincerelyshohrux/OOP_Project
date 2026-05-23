// Saydinabiyev Saidazizxon , U2510103

#include "order.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
using namespace std;

// Get todays date
string getCurrentDate() {
    time_t now = time(0);
    tm* t = localtime(&now);
    return to_string(t->tm_mday) + "/" + to_string(1 + t->tm_mon) + "/" + to_string(1900 + t->tm_year);
}

// Count orders in file to get next ID
int getNextOrderId() {
    ifstream file("orders.txt");
    string line;
    int count = 0;
    while (getline(file, line))
        if (line.find("ORDER #") != string::npos) count++;
    return count + 1;
}

// Reduce stock after purchase
void updateStock(vector<CartItem>& cart) {
    vector<Product> products = loadProducts();

    for (CartItem& item : cart)
        for (Product& p : products)
            if (p.getId() == item.getProduct().getId())
                p.setQuantity(p.getQuantity() - item.getQuantity());

    // Rewrite products.txt with updated quantities
    ofstream file("products.txt");
    for (Product& p : products)
        file << p.getId() << "," << p.getName() << "," << p.getPrice()
             << "," << p.getQuantity() << "," << p.getCategory() << "\n";
    file.close();
}

// Checkout with exception handling
void checkout(vector<CartItem>& cart, string username) {
    if (cart.empty()) { cout << "\nCart is empty!\n"; return; }

    try {
        int orderId = getNextOrderId();
        string date = getCurrentDate();
        double total = getTotal(cart);

        // Print receipt
        cout << "\n==========================================\n";
        cout << "             ORDER RECEIPT\n";
        cout << "==========================================\n";
        cout << "  Order ID : #" << orderId << "\n";
        cout << "  Customer : " << username << "\n";
        cout << "  Date     : " << date << "\n";
        cout << "------------------------------------------\n";

        for (CartItem& item : cart) {
            cout << "  " << left << setw(20) << item.getProduct().getName()
                 << " x" << item.getQuantity()
                 << "  $" << fixed << setprecision(2)
                 << (item.getProduct().getPrice() * item.getQuantity()) << "\n";
        }

        cout << "------------------------------------------\n";
        cout << "  TOTAL    : $" << fixed << setprecision(2) << total << "\n";
        cout << "------------------------------------------\n";
        cout << "      Thank you for shopping!\n";
        cout << "------------------------------------------\n";

        // Save to orders.txt
        ofstream file("orders.txt", ios::app);
        if (!file) throw runtime_error("Cannot open orders.txt!");

        file << "ORDER #" << orderId << " | " << username << " | " << date << "\n";
        for (CartItem& item : cart)
            file << "  - " << item.getProduct().getName()
                 << " x" << item.getQuantity()
                 << " = $" << fixed << setprecision(2)
                 << (item.getProduct().getPrice() * item.getQuantity()) << "\n";
        file << "  TOTAL: $" << fixed << setprecision(2) << total << "\n";
        file << "------------------------------------------\n";
        file.close();

        updateStock(cart);
        cart.clear();
        cout << "\nOrder saved! Cart cleared.\n";

    } catch (exception& e) {
        // Exception handling
        cout << "Checkout error: " << e.what() << "\n";
    }
}














