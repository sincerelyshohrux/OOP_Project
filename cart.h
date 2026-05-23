// Muminov Suxrobbek, U2510138

#pragma once
#include <vector>
#include "product.h"
using namespace std;

// CartItem class 
class CartItem {
private:
    Product product;
    int quantity;

public:
// Constructor
    CartItem(Product p, int q) {
        product  = p;
        quantity = q;
    }

// Getters
    Product getProduct()  { return product; }
    int     getQuantity() { return quantity; }
    void    addQuantity(int q) { quantity += q; }
};

void addToCart(vector<CartItem>& cart);
void showCart(vector<CartItem>& cart);
void removeFromCart(vector<CartItem>& cart);
double getTotal(vector<CartItem>& cart);