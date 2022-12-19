#include <iostream>
#include <climits>
#include <cassert>
#include <cstring>

template <typename T>
void swap(T &a, T &b) {
	T c = a;
	a	= b;
	b	= c;
}

template <typename T>
T exchange(T &a, const T &b) {
	T c = a;
	a	= b;
	return c;
}

template <typename T>
void printArray(const T *arr, size_t size) {
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}

template <typename T>
void readArray(const T *arr, size_t size) {
	for (int i = 0; i < size; ++i) {
		std::cin >> arr[i];
	}
}

template <typename T>
void multiplyArr(T *arr, size_t size, T num) {
	for (int i = 0; i < size; ++i) {
		arr[i] *= num;
	}
}

template <typename T>
T *find(const T *arr, size_t size, T elem) {
	for (int i = 0; i < size; ++i) {
		if (arr[i] == elem) { return arr + i; }
	}
	return nullptr;
}

bool isLetter(char a) { return ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')); }

const char *longestWord(const char *str) {
	const char *longest		   = nullptr;
	const char *currWord	   = str;
	uint		longestWordLen = 0;
	uint		wordLen		   = 0;
	for (int i = 0;; ++i) {
		if (isLetter(str[i])) {
			if (!wordLen) currWord = str + i;
			++wordLen;
		} else {
			if (longestWordLen < wordLen) {
				longestWordLen = wordLen;
				longest		   = currWord;
			}
			wordLen = 0;
		}
		if (str[i] == 0) break;
	}
	return longest;
}

template <typename T>
void minMaxElements(T *arr, size_t size, T &min, T &max) {
	min = std::numeric_limits<T>::max;
	max = std::numeric_limits<T>::min;
	for (int i = 0; i < size; ++i) {
		if (arr[i] > max) max = arr[i];
		if (arr[i] < min) min = arr[i];
	}
}

template <typename T>
void deleteAtIndex(T *arr, size_t size, size_t index) {
	assert(index < size);
	for(unsigned int i = index; i < size - 1; ++ i) {
		arr[i] = arr[i+1];
	}
}

template <typename T>
void reverse(T *arr, size_t size) {
	for(unsigned int i = 0; i < size / 2; ++ i) {
		swap(arr[i], arr[size - i - 1]);
	}
}

template <typename T>
void removeAllOccurences(T *arr, size_t size, T elem) {
	T *nextElem = arr;
	for(unsigned int i = 0; i < size; ++ i) {
		if(arr[i] != elem) {
			*nextElem = arr[i];
			++nextElem;
		}
	}
}


int main() {
	int a = 5, b = 10;
	swap(a, b);
	std::cout << a << " " << b << std::endl;

	char str [] = "HEllo my name is BobOooo";
	std::cout << strlen(str) << " " << sizeof(str);
	std::cout << longestWord(str) << std::endl;

	deleteAtIndex(str, sizeof(str), 2);
	std::cout << str << std::endl;
	
	reverse(str, sizeof(str) - 2);
	std::cout << str << std::endl;

	removeAllOccurences(str, sizeof(str) - 1, 'o');
	std::cout << str << std::endl;

}