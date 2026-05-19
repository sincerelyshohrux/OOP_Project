#pragma once
#include <vector>
#include "product.h"
using namespace std;

struct CartItem {
    Product product;
    int quantity;
};

void addToCart(vector<CartItem>& cart);
void showCart(vector<CartItem>& cart);
void removeFromCart(vector<CartItem>& cart);
double getTotal(vector<CartItem>& cart);
