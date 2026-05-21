#pragma once
#include <vector>
#include "product.h"
using namespace std;

// one item in the cart
struct CartItem {
    Product product;
    int quantity;  // how many the customer wants
};

// function declarations
void addToCart(vector<CartItem>& cart);
void showCart(vector<CartItem>& cart);
void removeFromCart(vector<CartItem>& cart);
double getTotal(vector<CartItem>& cart);