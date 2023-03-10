#include <iostream>
#include <algorithm>

template <typename T>
class Array {
	size_t size;
	T	  *arr;

   public:
	Array(size_t size) : size(size) { arr = new T(size); }

	~Array() { delete[] arr; }

	T &operator[](size_t i) { return arr[i]; }

	void sort(bool (*comp)(const T &, const T &)) { std::sort(arr, arr + size, comp); }

	void sort() {
		sort([](const T &a, const T &b) -> bool { return a < b; });
	}

	template <typename U>
	friend std::ostream &operator<<(std::ostream &out, Array<U> &arr);

	template <typename U>
	friend std::istream &operator>>(std::istream &in, Array<U> &arr);
};

template <typename T>
std::ostream &operator<<(std::ostream &out, Array<T> &arr) {
	for (size_t i = 0; i < arr.size; ++i) {
		out << arr[i];
	}
	return out;
}

template <typename U>
std::istream &operator>>(std::istream &in, Array<U> &arr) {
	for (size_t i = 0; i < arr.size; ++i) {
		in >> arr[i] >> ' ';
	}
	return in;
}

int main() {
	Array<int> arr(5);
	std::cin >> arr;
	arr.sort();
	std::cout << arr;
	return 0;
}