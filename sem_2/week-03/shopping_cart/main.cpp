#include <iostream>
#include "shopping_cart.hpp"
#include "product.hpp"

int main() {
	ShoppingCart sc;
	sc.addProduct(Product("palachinka", 1.0, 5));	  // dobavq se
	sc.addProduct(Product("palachinka", 2.0, 6));	  // ne se dobavq zashtoto se povtarq
	sc.addProduct(Product("banan", -2.0, 100));		  // dobavq se, no s cena 0
	sc.addProduct(Product("pechka", 500., 2));		  // dobavq se

	std::cout << sc << std::endl;	 // palachinka, banan, pechka

    sc.getProduct(0).setPrice(3.0);
	sc.removeProduct(1);

	std::cout << sc << std::endl;	 // palachinka, pechka
	return 0;
}