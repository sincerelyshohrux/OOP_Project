// Maxamatjonov Shohruxbek, U2510135
#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

// Product class 
class Product {
private:
    int id;
    string name;
    double price;
    int quantity;
    string category;

public:
    // Constructor
    Product(int i = 0, string n = "", double p = 0, int q = 0, string c = "") {
        id       = i;
        name     = n;
        price    = p;
        quantity = q;
        category = c;
    }

    // Getters
    int    getId()       { return id; }
    string getName()     { return name; }
    double getPrice()    { return price; }
    int    getQuantity() { return quantity; }
    string getCategory() { return category; }

    // Setters
    void setPrice(double p)    { price = p; }
    void setQuantity(int q)    { quantity = q; }

    // Operator << overloading
    friend ostream& operator<<(ostream& os, Product& p);
};

void addProduct();
void showAllProducts();
void showByCategory(string category);
vector<Product> loadProducts();
Product getProductById(int id);