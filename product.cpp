#include "product.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

// read all products from products.txt and return as vector
vector<Product> loadProducts() {
    vector<Product> products;
    ifstream file("products.txt");
    string line;
    
    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, price, qty, cat;
        
        // each line format: id,name,price,quantity,category
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, price, ',');
        getline(ss, qty, ',');
        getline(ss, cat, ',');
        
        products.push_back({stoi(id), name, stod(price), stoi(qty), cat});
    }
    return products;
}

// show only products from one category
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

// show all products grouped by category
void showAllProducts() {
    cout << "\n=== ALL PRODUCTS ===\n";
    showByCategory("phone");
    showByCategory("notebook");
    showByCategory("car");
}

// admin adds a new product
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

    // new id = total products + 1
    int newId = loadProducts().size() + 1;
    
    ofstream file("products.txt", ios::app);
    file << newId << "," << name << "," << price << "," << quantity << "," << category << "\n";
    file.close();
    
    cout << "Product added! (ID: " << newId << ")\n";
}

// find one product by its id
Product getProductById(int id) {
    for (Product p : loadProducts()) {
        if (p.id == id) return p;
    }
    return {-1, "", 0.0, 0, ""}; // return -1 id if not found
}






















