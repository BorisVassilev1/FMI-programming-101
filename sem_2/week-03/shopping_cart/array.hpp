#pragma once
#include <ostream>
#include <cstddef>

template <class T>
class Array {
   private:
	size_t size;
	size_t capacity;
	T	  *arr;

   public:
	Array();
	Array(Array<T> &other);
	Array &operator=(Array<T> &other);

	void resize(size_t cap);
	void push(T &elem);
	void erase(size_t ind);

	T &operator[](size_t ind);

	template<class E>
	friend std::ostream &operator<<(std::ostream &out, const Array<E> &arr);
};