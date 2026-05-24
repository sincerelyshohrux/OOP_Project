// Maxamatjonov Shohruxbek, U2510135
#include "product.h"
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

// operator overloading to print Product object
ostream& operator<<(ostream& os, Product& p) {

    // uutput product details in formatted style
    os << "  [" << p.id << "] "        // poduct ID
       << p.name                      // product name
       << " | $" 
       << fixed << setprecision(2)    // price with 2 decimal places
       << p.price
       << " | Stock: " 
       << p.quantity;                 // available quantity

    return os;                         // return output stream
}

// Reads all products from "products.txt" file
vector<Product> loadProducts() {

    vector<Product> products;         // stores all loaded products
    ifstream file("products.txt");     // open file for reading
    string line;                       // stores each line from file

    // read file line by line
    while (getline(file, line)) {
        stringstream ss(line);         // break line into parts
        string id, name, price, quan, cate;

        // split data using comma as delimiter
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, price, ',');
        getline(ss, quan, ',');
        getline(ss, cate, ',');

        // convert string values to appropriate data types
        try {
            products.push_back(
                Product(
                    stoi(id),          // convert ID to int
                    name,
                    stod(price),       // convert price to double
                    stoi(quan),         // convert quantity to int
                    cate
                )
            );
        }
        catch (exception& e) {
            // handle invalid data in file
            cout << "Error reading product: " << e.what() << "\n";
        }
    }

    return products;                  // return all loaded products
}

// displays products belonging to a specific category
void showByCategory(string category) {

    vector<Product> products = loadProducts();   // load all products
    cout << "\n--- " << category << " catalog ---\n";

    bool found = false;                           // track if any product is found

    // loop through all products
    for (Product p : products) {

        // check if product category matches
        if (p.getCategory() == category) {
            found = true;
            cout << p << "\n";                    // uses operator<<
        }
    }

    // if no products found in this category
    if (!found)
        cout << "  No products found!\n";
}

// show all products grouped by category
void showAllProducts() {
    cout << "\n=== ALL PRODUCTS ===\n";
    showByCategory("phone");        // display phone
    showByCategory("notebook");
    showByCategory("car");
}

// allows admin to add a new product
void addProduct() {

    string name, category;
    double price;
    int quantity, cateChoice;

    cout << "\n=== ADD PRODUCT ===\n";

    cout << "Name: ";
    cin.ignore();                  // clear input buffer
    getline(cin, name);            // read product name

    cout << "Price: ";
    cin >> price;

    cout << "Quantity: ";
    cin >> quantity;

    cout << "Category (1-Phone, 2-Notebook, 3-Car): ";
    cin >> cateChoice;

    // determine category based on user choice
    if      (cateChoice == 1) category = "phone";
    else if (cateChoice == 2) category = "notebook";
    else if (cateChoice == 3) category = "car";
    else {
        cout << "Invalid category!\n";
        return;
    }

    // generate new product ID
    int newId = loadProducts().size() + 1;

    // open file in append mode and save product
    ofstream file("products.txt", ios::app);
    file << newId << "," << name << "," << price << ","
         << quantity << "," << category << "\n";
    file.close();

    cout << "Product added! (ID: " << newId << ")\n";
}
// finds and returns a product by its ID
Product getProductById(int id) {

    // loop through all products
    for (Product p : loadProducts()) {

        if (p.getId() == id)
            return p;              // return product if found
    }

    // return invalid product if not found
    return Product(-1, "", 0, 0, "");
}


















