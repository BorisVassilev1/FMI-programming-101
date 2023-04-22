#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <cstring>
#include <ostream>
#include <system_error>

// клас Medicine
class Medicine {
	std::uint32_t number;
	char		 *name;
	std::uint32_t activeSubstance;
	double		  price;

	public:

	Medicine() : number(0), name(new char[1]{'\0'}), activeSubstance(0), price(0.0) {}
	Medicine(std::uint32_t number, const char *name, std::uint32_t activeSubstance, double price) :
	number(number), name(new char[std::strlen(name) + 1]), activeSubstance(activeSubstance), price(price) {
		std::strcpy(this->name, name);
	}

	Medicine(const Medicine &other) : 
		number(other.number),
		name(new char[std::strlen(other.name) + 1]),
		activeSubstance(other.activeSubstance),
		price(other.price) {
		strcpy(this->name,other.name);
	}

	Medicine &operator=(const Medicine &other) {
		delete [] this->name;
		this->name = new char[std::strlen(other.name) + 1];
		strcpy(this->name, other.name);
		this->number = other.number;
		this->activeSubstance = other.activeSubstance;
		this->price = other.price;
		return *this;
	}

	~Medicine() {
		delete [] this->name;
	}

	std::uint32_t getNumber() {
		return number;
	}
	
	const char *getName() {
		return name;
	}
	
	std::uint32_t getActiveSubstance() {
		return activeSubstance;
	}

	void print() {
		std::cout << "number: " << number;
		std::cout << " name: " << name;
		std::cout << " activeSubstance: " << activeSubstance;
		std::cout << " price: " << price;
	}

	bool operator<(const Medicine &other) {
		int res = std::strcmp(this->name, other.name);
		if(res != 0) return res < 0;
		else return this->activeSubstance < other.activeSubstance;
	}
};

// сортираща функция
void sort(Medicine *arr, std::size_t size) {
	std::sort(arr, arr + size);
}

int main() {
	Medicine arr[10];
	arr[0] = Medicine(1, "asd", 10, 12.);
	arr[1] = Medicine(1, "bsd", 10, 12.);
	arr[2] = Medicine(1, "asd", 1, 12.);
	

	sort(arr, 3);

	for(std::size_t i = 0; i < 3; ++ i) {
		arr[i].print();
		std::endl(std::cout);
	}
	return 0;
}
