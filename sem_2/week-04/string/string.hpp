#include <cstddef>
#include <ostream>
#include <iostream>
#include <cstring>

template <class T>
class basic_string {
	T		   *arr;
	std::size_t count;
	std::size_t capacity;

	void resize(size_t size);
	void resize();

   public:
	basic_string();
	basic_string(const basic_string<T> &other);
	basic_string(const T* str);
	~basic_string();
	basic_string &operator=(const basic_string<T> &other);

	bool		empty() const;
	std::size_t size() const;
	void		copy(basic_string<T> &dest, size_t count) const;
	basic_string<T>	substr(size_t begin, size_t count) const;

	T		  &operator[](size_t i) const;
	basic_string<T> &operator+=(const basic_string<T> &other);
	basic_string<T>  operator+(const basic_string<T> &other) const;
	int		   operator<=>(const basic_string<T> &other) const;
			   operator T *();

	void push(const T &elem);
};

template <class T>
void basic_string<T>::resize(size_t newSize) {
	T *newArr = new T[newSize];
	memcpy(newArr, this->arr, (this->count + 1) * sizeof(T));
	delete [] this->arr;
	this->arr	   = newArr;
	this->capacity = newSize;
}

template <class T>
void basic_string<T>::resize() {
	resize(this->capacity << 1);
}

template <class T>
std::ostream &operator<<(std::ostream &out, const basic_string<T> &vec) {
	for (size_t i = 0; i < vec.size(); ++i) {
		out << vec[i];
	}
	return out;
}

template <class T>
basic_string<T>::basic_string() : arr(new T[1]{0}), count(0), capacity(1) {}

template <class T>
basic_string<T>::basic_string(const basic_string<T> &other) : arr(new T[other.capacity]), count(other.count), capacity(other.capacity) {
	memcpy(this->arr, other.arr, (other.count + 1) * sizeof(T));
}

template<class T>
basic_string<T>::basic_string(const T* str) : arr(nullptr), count(0), capacity(0) {
	std::size_t size = strlen(str);
	this->arr = new T[size + 1];
	this->count = size;
	this->capacity = size + 1;
	memcpy(this->arr, str, (size + 1) * sizeof(T));
}

template <class T>
basic_string<T>::~basic_string() {
	delete [] this->arr;
}

template <class T>
basic_string<T> &basic_string<T>::operator=(const basic_string<T> &other) {
	if (this != *other) return *this;
	delete this->arr;
	this->arr	   = new T[other.capacity];
	this->count	   = other.count;
	this->capacity = other.capacity;
	memcpy(this->arr, other.arr, (this->count + 1) * sizeof(T));
	return *this;
}

template <class T>
bool basic_string<T>::empty() const {
	return this->count == 0;
}

template <class T>
std::size_t basic_string<T>::size() const {
	return this->count;
}

template <class T>
void basic_string<T>::copy(basic_string<T> &dest, size_t count) const {
	if (count > this->count) count = this->count;
	size_t free_space = dest.capacity - dest.count;
	if (free_space < count) { dest.resize(dest.count + count + 1); }
	memcpy(dest.arr + dest.count, this->arr, (count + 1) * sizeof(T));
	dest.count += count;
}

template <class T>
basic_string<T> basic_string<T>::substr(size_t begin, size_t count) const {
	if (begin + count > this->count) count = this->count - begin;
	basic_string<T> vec;
	vec.resize(count + 1);
	vec.count = count;
	memcpy(vec.arr, this->arr + begin, count * sizeof(T));
	vec[count] = 0;
	return vec;
}

template <class T>
T &basic_string<T>::operator[](size_t i) const {
	return this->arr[i];
}

template <class T>
basic_string<T> &basic_string<T>::operator+=(const basic_string<T> &other) {
	other.copy(*this, other.count);
	return *this;
}

template <class T>
inline basic_string<T> basic_string<T>::operator+(const basic_string<T> &other) const {
	basic_string<T> vec(*this);
	other.copy(vec, other.count);
	return vec;
}

template <class T>
inline basic_string<T>::operator T *() {
	return this->arr;
}

template <class T>
int basic_string<T>::operator<=>(const basic_string<T> &other) const {
	for(std::size_t i = 0; i < other.size() && i < this->size(); ++ i) {
		if((*this)[i] != other[i]) {
			return (*this)[i] - other[i];
		}
	}
	return 0;
}

template <class T>
void basic_string<T>::push(const T &elem) {
	if (this->count + 1 == this->capacity) this->resize();
	this->arr[this->count] = elem;
	this->arr[this->count] = 0;
	++this->count;
}

using string = basic_string<char>;
