// Maxamatjonov Shohruxbek, U2510135
#include "product.h"
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

// Operator overloading  print product 
ostream& operator<<(ostream& os, Product& p) {
    os << "  [" << p.id << "] " << p.name
       << " | $" << fixed << setprecision(2) << p.price
       << " | Stock: " << p.quantity;
    return os;
}

// Read all products from products.txt
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

        // Exception handling when reading file
        try {
            products.push_back(Product(stoi(id), name, stod(price), stoi(qty), cat));
        } catch (exception& e) {
            cout << "Error reading product: " << e.what() << "\n";
        }
    }
    return products;
}

// Show products by category using operator
void showByCategory(string category) {
    vector<Product> products = loadProducts();
    cout << "\n--- " << category << " catalog ---\n";
    bool found = false;
    for (Product p : products) {
        if (p.getCategory() == category) {
            found = true;
            cout << p << "\n";   // uses operator
        }
    }
    if (!found) cout << "  No products found!\n";
}

// Show all products grouped by category
void showAllProducts() {
    cout << "\n=== ALL PRODUCTS ===\n";
    showByCategory("phone");
    showByCategory("notebook");
    showByCategory("car");
}

// Admin adds a new product
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

// Find product by ID
Product getProductById(int id) {
    for (Product p : loadProducts()) {
        if (p.getId() == id) return p;
    }
    return Product(-1, "", 0, 0, "");
}



















