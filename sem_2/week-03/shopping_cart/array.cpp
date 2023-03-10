#include "array.hpp"

template <class T>
Array<T>::Array(Array<T>& other) {
	arr = new T[other.capacity];
	memcpy(arr, other.arr, other.size * sizeof(T));
	capacity = other.capacity;
	size = other.size;
}

template <class T>
Array<T>::Array() : arr(new T[1]), size(0), capacity(1) {}

template <class T>
Array<T>& Array<T>::operator=(Array<T>& other) {
	delete arr;
	arr = new T[other.capacity];
	memcpy(arr, other.arr, other.size * sizeof(T));
	capacity = other.capacity;
	size = other.size;
	return *this;
}

template <class T>
void Array<T>::resize(size_t cap) {
	T *resized = new T[cap];
	memcpy(resized, arr, size * sizeof(T));
	delete arr;
	arr = resized;
	capacity = cap;
}

template <class T>
void Array<T>::push(T& elem) {
	if(size == capacity) resize(capacity << 1);
	arr[size] = elem;
	++ size;
}

template <class T>
void Array<T>::erase(size_t ind) {
	for(int i = ind; i < size - 1) {
		arr[i] = arr[i + 1];
	}
	-- size;
}
