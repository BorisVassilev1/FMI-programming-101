#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using uint = uint32_t;

const int maxN = 1e7 + 10;

int src[maxN];
int dest[maxN];

void print(const int *arr, uint len) {
	for (uint i = 0; i < len; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void mergeBottomUp(const int *src, int *dest, const uint begin, const uint runWidth, const uint len) {
	const uint end	= std::min(begin + 2 * runWidth, len);
	const uint half = std::min(begin + runWidth, len);
	// cout << "merge: " << begin << " " << end << endl;
	uint ptr  = begin;
	uint ptr1 = begin, ptr2 = std::min(begin + runWidth, len);
	while (ptr < end) {
		// std::cout << "p1: " << ptr1 << " p2: " << ptr2 << endl;
		if (ptr1 == half) {
			dest[ptr] = src[ptr2];
			++ptr2;
		} else if (ptr2 == end || src[ptr1] < src[ptr2]) {
			dest[ptr] = src[ptr1];
			++ptr1;
		} else {
			dest[ptr] = src[ptr2];
			++ptr2;
		}
		++ptr;
	}
}

int *mergeSort(int *src, int *dest, const uint len) {
	uint runWidth = 1;
	uint i		  = 0;
	int *front = src, *back = dest;
	for (; runWidth < len; runWidth <<= 1, ++i) {
		const uint step = 2 * runWidth;
		for (uint i = 0; i < len; i += step) {
			mergeBottomUp(front, back, i, runWidth, len);
		}
		std::swap(front, back);
	}
	return i%2 ? dest : src;
}

int main() {
	uint n;
	cin >> n;
	for (uint i = 0; i < n; ++i) {
		cin >> src[i];
	}

	int *res = mergeSort(src, dest, n);

	print(res, n);
	return 0;
}