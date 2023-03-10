#include <cstring>
#include <iomanip>
#include <iostream>
#include "product.hpp"

char* Product::copyString(const char* str) {
	char* copy = new char[strlen(str) + 1];
	strcpy(copy, str);
	return copy;
}

void Product::setName(const char* str) {
	if (name != nullptr) { delete name; }
	name = copyString(str);
}

bool Product::checkPrice(float price) const {
	return price >= 0;
}

Product::Product() : name(new char[1]{'\0'}), price(0), quantity(0) {}

Product::Product(const char* name, float price, unsigned int quantity)
	: name(nullptr), price(price), quantity(quantity) {
	setName(name);
	if (!checkPrice(price)) {
		this->price	   = 0;
		this->quantity = 0;
	}
}

Product::Product(const Product& other) : name(nullptr), price(other.price), quantity(other.quantity) {
	setName(other.name);
}

Product& Product::operator=(const Product& other) {
	if (&other != this) {
		setName(other.name);
		price	 = other.price;
		quantity = other.quantity;
	}
	return *this;
}

Product::~Product() {
	if (name != nullptr) delete[] name;
}

const char* Product::getName() const {
	return name;
}

float Product::getPrice() const {
	return price;
}

void Product::setPrice(float price) {
	if (checkPrice(price)) this->price = price;
}

unsigned int Product::getQuantity() const {
	return quantity;
}

void Product::setQuantity(unsigned int quantity) {
	this->quantity = quantity;
}

float Product::getTotalPrice() const {
	return price * quantity;
}

bool Product::operator==(const Product& other) const{
	return strcmp(name, other.name) == 0;
}

std::ostream& operator<<(std::ostream& os, const Product& p) {
	os << "Product: {name: \"" << p.name << "\" price: " << p.price << " quantity: " << p.quantity << " }";
	return os;
}
