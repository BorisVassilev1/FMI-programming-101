#include <iostream>
#include <cstring>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using uint = uint32_t;

const int maxN = 1e7 + 10;

int src[maxN];

void print(const int *arr, uint len) {
	for (uint i = 0; i < len; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	uint n;
	cin >> n;
	for (uint i = 0; i < n; ++i) {
		cin >> src[i];
	}

	std::sort(src, src + n);

	print(src, n);
	return 0;
}