#include <iostream>
#include <cstddef>
#include <iomanip>

int ***Allocate(std::size_t n, std::size_t m, std::size_t k) {
	// allocate arrays
	int ***res = new int **[n];
	res[0]	   = new int *[n * m];
	res[0][0]  = new int[n * m * k];
	
	// initialize pointers
	for (std::size_t i = 1; i < n; ++i) {
		res[i] = res[0] + i * m;
	}
	for (std::size_t i = 1; i < n * m; ++i) {
		res[0][i] = res[0][0] + k * i;
	}
	return res;
}
void Init(int ***arr, std::size_t n, std::size_t m, std::size_t k) {
	// fill array with numbers
	for (std::size_t i = 0; i < n * m * k; ++i) {
		arr[0][0][i] = i;
	}
}

void Print(int ***arr, std::size_t n, std::size_t m, std::size_t k) {
	// print slice by slice
	for (std::size_t i = 0; i < n; ++i) {
		for (std::size_t j = 0; j < m; ++j) {
			for (std::size_t l = 0; l < k; ++l) {
				std::cout << std::setw(4) << arr[i][j][l];
			}
			std::cout << '\n';
		}
		std::cout << '\n';
	}
}

void Deallocate(int ***arr) {
	delete [] arr[0][0];
	delete [] arr[0];
	delete [] arr;
}

int main() {
	std::size_t n, m, k;
	std::cout << "Enter array dimensions n, m, k: " << std::flush;
	std::cin >> n >> m >> k;

	int *** arr = Allocate(n, m, k);
	Init(arr, n, m, k);
	Print(arr, n, m, k);
	Deallocate(arr);

	return 0;
}