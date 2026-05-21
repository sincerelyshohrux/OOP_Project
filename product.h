#pragma once
#include <string>
#include <vector>
using namespace std;

// product data structure
struct Product {
    int id;
    string name;
    double price;
    int quantity;
    string category;  // "phone", "notebook", "car"
};

// function declarations
void addProduct();
void showAllProducts();
void showByCategory(string category);
vector<Product> loadProducts();
Product getProductById(int id);