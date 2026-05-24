// Maxamatjonov Shohruxbek, U2510135
#pragma once        // prevents multiple inclusion of this header file
#include <string>       // for using string type 
#include <vector>      // for using vekctor container 
#include <iostream>       // for input and output streams
using namespace std;

// Product class 
class Product {
private:
    int id;       // unique product id 
    string name;
    double price;
    int quantity;     // stock quantity
    string category;

public:
    // constructor
    // default values are used if no arguments are passed
    Product(int i = 0, string n = "", double p = 0, int q = 0, string c = "") {
        id       = i;
        name     = n;
        price    = p;
        quantity = q;
        category = c;
    }

    // getters
    // used to safely access private variables
    int    getId()       { return id; }
    string getName()     { return name; }
    double getPrice()    { return price; }
    int    getQuantity() { return quantity; }
    string getCategory() { return category; }

    // setters
    // used to update specific values
    void setPrice(double p)    { price = p; }
    void setQuantity(int q)    { quantity = q; }

    // Operator overloading
    // allows print product using cout product
    friend ostream& operator<<(ostream& os, Product& p);
};

void addProduct(); // add new product 
void showAllProducts();  // show all poducts
void showByCategory(string category);   // show product by category 
vector<Product> loadProducts();   // load product from file 
Product getProductById(int id);    // find product id