#include <iostream>
#include <iomanip>
#include "shopping_cart.hpp"

std::ostream &operator<<(std::ostream &os, const ShoppingCart &cart) {
	os << "ShoppingCart: { \n\tsize: " << cart.getSize() << "\n\tproducts: \n";
    for(unsigned i = 0; i < cart.products.size(); ++ i) {
        os << "\t" << std::setw(3) << i << " : " << cart.products[i] << '\n';
    }
    os << "\ttotal value: " << cart.getTotalPrice() << "\n}";
	return os;
}

unsigned int ShoppingCart::getSize() const {
	return products.size();
}

void ShoppingCart::addProduct(const Product &product) {
    for(Product &p : products) {
        if(p == product) {
            return;
        }
    }
    products.push_back(product);
}

void ShoppingCart::removeProduct(unsigned int index) {
    products.erase(products.begin() + index);
}

Product &ShoppingCart::getProduct(unsigned int index) {
    return products[index];
}

float ShoppingCart::getTotalPrice() const {
	float res = 0;
    for(const Product &p : products) {
        res += p.getTotalPrice();
    }
    return res;
}
