#pragma once
#include <ostream>

class Product {
   private:
	char		*name;
	float		 price;
	unsigned int quantity;

	char *copyString(const char *str);
	void setName(const char *str);
	bool checkPrice(float price) const;

   public:
	Product();
	Product(const char *name, float price, unsigned int quantity);
	Product(const Product &other);
	Product &operator=(const Product &other);
	~Product();
	const char	*getName() const;
	float		 getPrice() const;
	void		 setPrice(float price);
	unsigned int getQuantity() const;
	void		 setQuantity(unsigned int quantity);

	float getTotalPrice() const;

	friend std::ostream &operator<<(std::ostream &os, const Product &rhs);
	bool operator==(const Product &other) const; 
};