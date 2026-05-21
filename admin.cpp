#include "admin.h"
#include "product.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// admin  delete a product from the store
void deleteProduct() {
    
    // first show all products so admin can see the ids
    showAllProducts();
    
    int id;
    cout << "\nEnter product ID to delete: ";
    cin >> id;

    // load all products from file
    vector<Product> products = loadProducts();
    bool found = false;
    
    // open file to rewrite it without the deleted product
    ofstream file("products.txt");
    
    for (Product& p : products) {
        // product we want to delete
        if (p.id == id) {
            found = true;
            cout << p.name << " deleted!\n";
            continue;
        }
        // write everything else back to file
        file << p.id << "," << p.name << "," << p.price << "," << p.quantity << "," << p.category << "\n";
    }
    file.close();
    
    if (!found) cout << "Product not found!\n";
}

// admin change price or quantity of a product
void editProduct() {
    showAllProducts();
    
    int id;
    cout << "\nEnter product ID to edit: ";
    cin >> id;

    vector<Product> products = loadProducts();
    bool found = false;

    for (Product& p : products) {
        if (p.id == id) {
            found = true;
            
            // show current values and ask what to change
            cout << "1. Edit price (current: $" << fixed << setprecision(2) << p.price << ")\n";
            cout << "2. Edit quantity (current: " << p.quantity << ")\n";
            cout << "Select: ";
            
            int choice;
            cin >> choice;
            
            if (choice == 1) {
                cout << "New price: ";
                cin >> p.price;
                cout << "Price updated!\n";
            }
            else if (choice == 2) {
                cout << "New quantity: ";
                cin >> p.quantity;
                cout << "Quantity updated!\n";
            }
            else {
                cout << "Invalid choice!\n";
            }
            break;
        }
    }

    if (!found) {
        cout << "Product not found!\n";
        return;
    }

    // save updated products back to file
    ofstream file("products.txt");
    for (Product& p : products)
        file << p.id << "," << p.name << "," << p.price << "," << p.quantity << "," << p.category << "\n";
    file.close();
}

// show all orders from orders.txt
void viewOrders() {
    ifstream file("orders.txt");
    string line;
    
    cout << "\n--- ALL ORDERS ---\n";
    
    bool hasOrders = false;
    while (getline(file, line)) {
        hasOrders = true;
        cout << line << "\n";
    }
    if (!hasOrders) cout << "No orders yet!\n";
}











