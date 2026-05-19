#include "product.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

vector<Product> loadProducts() {
    vector<Product> products;
    ifstream file("products.txt");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, price, qty, cat;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, price, ',');
        getline(ss, qty, ',');
        getline(ss, cat, ',');
        products.push_back({stoi(id), name, stod(price), stoi(qty), cat});
    }
    return products;
}

void showByCategory(string category) {
    vector<Product> products = loadProducts();
    cout << "\n--- " << category << " catalog ---\n";
    bool found = false;
    for (Product p : products) {
        if (p.category == category) {
            found = true;
            cout << "  [" << p.id << "] " << p.name
                 << " | $" << fixed << setprecision(2) << p.price
                 << " | Stock: " << p.quantity << "\n";
        }
    }
    if (!found) cout << "  No products found!\n";
}

void showAllProducts() {
    cout << "\n=== ALL PRODUCTS ===\n";
    showByCategory("phone");
    showByCategory("notebook");
    showByCategory("car");
}

void addProduct() {
    string name, category;
    double price;
    int quantity, catChoice;

    cout << "\n=== ADD PRODUCT ===\n";
    cout << "Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Price: ";
    cin >> price;
    cout << "Quantity: ";
    cin >> quantity;
    cout << "Category (1-Phone, 2-Notebook, 3-Car): ";
    cin >> catChoice;

    if      (catChoice == 1) category = "phone";
    else if (catChoice == 2) category = "notebook";
    else if (catChoice == 3) category = "car";
    else { cout << "Invalid category!\n"; return; }

    int newId = loadProducts().size() + 1;
    ofstream file("products.txt", ios::app);
    file << newId << "," << name << "," << price << "," << quantity << "," << category << "\n";
    file.close();
    cout << "Product added! (ID: " << newId << ")\n";
}

Product getProductById(int id) {
    for (Product p : loadProducts()) {
        if (p.id == id) return p;
    }
    return {-1, "", 0.0, 0, ""};
}
