#include <iostream>

using uint = uint32_t;
using std::cout;

void print(int arr[], uint size) {
    cout << "{ ";
	for (uint i = 0; i < size; ++i) {
		cout << arr[i] << " ";
	}
    cout << '}' << std::endl;
}

int dedup(int arr[], uint size) {
	uint unique = 0;
	uint dup	= 0;
	for (uint i = 0; i < size - dup; ++i) {
		bool u = true;
		for (int j = 0; j < i; ++j) {
			if (arr[i] == arr[j]) u = false;
		}
		if (u) ++unique;
		else {
			int tmp				= arr[size - dup - 1];
			arr[size - dup - 1] = arr[i];
			arr[i]				= tmp;
			++dup;
			--i;
		}
	}

	return unique;
}

int main() {
	int arr[] = {3, 3, 3, 2, 5, 3};

	cout << dedup(arr, 6) << " ";
    print(arr, 6);
}