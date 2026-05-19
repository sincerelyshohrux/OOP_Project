#pragma once
#include <string>
#include <vector>
#include "cart.h"
using namespace std;

void checkout(vector<CartItem>& cart, string username);
void updateStock(vector<CartItem>& cart);
