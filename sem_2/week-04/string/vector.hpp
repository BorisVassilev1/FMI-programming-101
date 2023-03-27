#include <cstddef>
#include <ostream>
#include <iostream>
#include <cstring>

template <class T>
class vector {
	T		   *arr;
	std::size_t count;
	std::size_t capacity;

	void resize(size_t size);
	void resize();

   public:
	vector();
	vector(const vector<T> &other);
	~vector();
	vector &operator=(const vector<T> &other);

	bool		empty() const;
	std::size_t size() const;
	void		copy(vector<T> &dest, size_t count) const;
	vector<T>	substr(size_t begin, size_t count) const;

	T		  &operator[](size_t i) const;
	vector<T> &operator+=(const vector<T> &other);
	vector<T>  operator+(const vector<T> &other) const;
	int		   operator<=>(const vector<T> &other) const;
			   operator T *();

	void push(const T &elem);
};
template <class T>
void vector<T>::resize(size_t newSize) {
	T *newArr = new T[newSize];
	memcpy(newArr, this->arr, this->count * sizeof(T));
	delete this->arr;
	this->arr	   = newArr;
	this->capacity = newSize;
}

template <class T>
void vector<T>::resize() {
	resize(this->capacity << 1);
}

template <class T>
std::ostream &operator<<(std::ostream &out, const vector<T> &vec) {
	for (size_t i = 0; i < vec.size(); ++i) {
		out << vec[i];
	}
	return out;
}

template <class T>
vector<T>::vector() : arr(new T[1]{0}), count(0), capacity(1) {}

template <class T>
vector<T>::vector(const vector<T> &other) : arr(new T[other.capacity]), count(other.count), capacity(other.capacity) {
	memcpy(this->arr, other.arr, other.count * sizeof(T));
}

template <class T>
vector<T>::~vector() {
	delete this->arr;
}

template <class T>
vector<T> &vector<T>::operator=(const vector<T> &other) {
	if (this != *other) return *this;
	delete this->arr;
	this->arr	   = new T[other.capacity];
	this->count	   = other.count;
	this->capacity = other.capacity;
	memcpy(this->arr, other.arr, this->count * sizeof(T));
	return *this;
}

template <class T>
bool vector<T>::empty() const {
	return this->count == 0;
}

template <class T>
std::size_t vector<T>::size() const {
	return this->count;
}

template <class T>
void vector<T>::copy(vector<T> &dest, size_t count) const {
	if (count > this->count) count = this->count;
	size_t free_space = dest.capacity - dest.count;
	if (free_space < count) { dest.resize(dest.count + count); }
	memcpy(dest.arr + dest.count, this->arr, count * sizeof(T));
	dest.count += count;
}

template <class T>
vector<T> vector<T>::substr(size_t begin, size_t count) const {
	if (begin + count > this->count) count = this->count - begin;
	vector<T> vec;
	vec.resize(count);
	vec.count = count;
	memcpy(vec.arr, this->arr + begin, count * sizeof(T));
	return vec;
}

template <class T>
T &vector<T>::operator[](size_t i) const {
	return this->arr[i];
}

template <class T>
vector<T> &vector<T>::operator+=(const vector<T> &other) {
	other.copy(*this, other.count);
	return *this;
}

template <class T>
inline vector<T> vector<T>::operator+(const vector<T> &other) const {
	vector<T> vec(*this);
	other.copy(vec, other.count);
	return vec;
}

template <class T>
inline vector<T>::operator T *() {
	return this->arr;
}

template <class T>
int vector<T>::operator<=>(const vector<T> &other) const {
	for(std::size_t i = 0; i < other.size() && i < this->size(); ++ i) {
		if((*this)[i] != other[i]) {
			return (*this)[i] - other[i];
		}
	}
	return 0;
}

template <class T>
void vector<T>::push(const T &elem) {
	if (this->count == this->capacity) this->resize();
	this->arr[this->count] = elem;
	++this->count;
}

