#include "order.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
using namespace std;

// get todays date as a string
string getCurrentDate() {
    time_t now = time(0);
    tm* t = localtime(&now);
    return to_string(t->tm_mday) + "/" + to_string(1 + t->tm_mon) + "/" + to_string(1900 + t->tm_year);
}

// count how many orders are in orders.txt to get next id
int getNextOrderId() {
    ifstream file("orders.txt");
    string line;
    int count = 0;
    while (getline(file, line))
        if (line.find("ORDER #") != string::npos) count++;
    return count + 1;
}

// reduce stock in products.txt after a purchase
void updateStock(vector<CartItem>& cart) {
    vector<Product> products = loadProducts();
    
    // subtract bought quantity from each product
    for (CartItem& item : cart)
        for (Product& p : products)
            if (p.id == item.product.id)
                p.quantity -= item.quantity;

    // rewrite products.txt with new quantities
    ofstream file("products.txt");
    for (Product& p : products)
        file << p.id << "," << p.name << "," << p.price << "," << p.quantity << "," << p.category << "\n";
    file.close();
}

// process the order, print receipt, save to file
void checkout(vector<CartItem>& cart, string username) {
    if (cart.empty()) { cout << "\nCart is empty!\n"; return; }

    int orderId = getNextOrderId();
    string date = getCurrentDate();
    double total = getTotal(cart);

    // print receipt to screen
    cout << "\n==========================================\n";
    cout << "             ORDER RECEIPT\n";
    cout << "==========================================\n";
    cout << "  Order ID : #" << orderId << "\n";
    cout << "  Customer : " << username << "\n";
    cout << "  Date     : " << date << "\n";
    cout << "------------------------------------------\n";
    
    for (CartItem& item : cart) {
        cout << "  " << left << setw(20) << item.product.name
             << " x" << item.quantity
             << "  $" << fixed << setprecision(2) << (item.product.price * item.quantity) << "\n";
    }
    
    cout << "------------------------------------------\n";
    cout << "  TOTAL    : $" << fixed << setprecision(2) << total << "\n";
    cout << "------------------------------------------\n";
    cout << "      Thank you for shopping!\n";
    cout << "------------------------------------------\n";

    // save order to orders.txt
    ofstream file("orders.txt", ios::app);
    file << "ORDER #" << orderId << " | " << username << " | " << date << "\n";
    for (CartItem& item : cart)
        file << "  - " << item.product.name << " x" << item.quantity
             << " = $" << fixed << setprecision(2) << (item.product.price * item.quantity) << "\n";
    file << "  TOTAL: $" << fixed << setprecision(2) << total << "\n";
    file << "------------------------------------------\n";
    file.close();

    // update stock and clear cart
    updateStock(cart);
    cart.clear();
    cout << "\nOrder saved! Cart cleared.\n";
}




















