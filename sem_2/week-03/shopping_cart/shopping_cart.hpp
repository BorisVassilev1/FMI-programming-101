#pragma once
#include <vector>
#include <ostream>
#include "product.hpp"
#include "array.hpp"

class ShoppingCart {
   private:
	std::vector<Product> products;

   public:
	unsigned int getSize() const;
	void		 addProduct(const Product &product);
	void		 removeProduct(unsigned int index);
	Product		&getProduct(unsigned int index);
	float		 getTotalPrice() const;

	friend std::ostream &operator<<(std::ostream &os, const ShoppingCart &cart);
};