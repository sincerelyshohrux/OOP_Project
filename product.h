#pragma once
#include <string>
#include <vector>
using namespace std;

struct Product {
    int id;
    string name;
    double price;
    int quantity;
    string category;
};

void addProduct();
void showAllProducts();
void showByCategory(string category);
vector<Product> loadProducts();
Product getProductById(int id);
