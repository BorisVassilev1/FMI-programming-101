#include <cstddef>
#include <iostream>
#include <cstring>
#include <istream>
#include <ostream>

template <class T>
class Bag {
	T		   *arr;
	std::size_t size;
	std::size_t capacity;

	void resize() {
		std::size_t newCap = capacity << 1;
		T		   *newArr = new T[newCap];
		memcpy(newArr, arr, size * sizeof(T));
		capacity = newCap;
		delete [] arr;
		arr = newArr;
	}

	void copy(const Bag &other) {
		if (arr != nullptr) delete [] arr;
		arr = new T[other.size];
		memcpy(arr, other.arr, other.size * sizeof(T));
		size	 = other.size;
		capacity = other.capacity;
	}

   public:
	Bag() : arr(new T[1]), size(0), capacity(1) {}
	Bag(const Bag &other) : arr(nullptr) { copy(other); }
	Bag &operator=(const Bag &other) {
		if (&other != this) copy(other);
	}
	~Bag() {
		delete [] arr;
		arr		 = nullptr;
		size	 = 0;
		capacity = 0;
	}

	void add(const T &elem) {
		if(size == capacity) resize();
		arr[size] = elem;
		++ size;
	}
	
	T get() {
		size --;
		return arr[size];
	}
	
	Bag operator+(const Bag &other) const {
		Bag res;
		for(std::size_t i = 0; i < size; ++ i) {
			res.add(arr[i]);
		}
		
		for(std::size_t i = other.size; i > 0; -- i) {
			res.add(other.arr[i - 1]);
		}
		return res;
	}

	bool operator==(const Bag &other) const {
		if(size != other.size) return false;
		for(size_t i = 0; i < size; ++ i) {
			if(arr[i] != other.arr[i]) {
				return false;
			}
		}
		return true;
	}
	
	friend std::ostream &operator<<(std::ostream &out, const Bag &bag) {
		for(std::size_t i = 0; i < bag.size; ++ i) {
			out << bag.arr[i] << ' ';
		}
		return out;
	}
};

int main() {
	Bag<int> b;
	b.add(1);
	b.add(2);
	b.add(3);
	Bag<int> a;
	a.add(4);
	a.add(5);

	std::cout << b + a << std::endl;

	Bag<int> c;
	c.add(1);
	c.add(2);
	c.add(3);
	c.add(5);
	c.add(4);

	std::cout << (b + a == c);

}
