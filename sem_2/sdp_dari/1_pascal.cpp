#include <iostream>
#include <cstddef>

int **Allocate(std::size_t rows) {
	// allocate pointer array
	int **res = new int *[rows];

	for (std::size_t i = 0; i < rows; ++i) {
		// allocate row
		res[i]	  = new int[i + 1];

		// fill pascal's triangle
		res[i][0] = 1;
		res[i][i] = 1;
		for (std::size_t j = 1; j < i; ++j) {
			res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
		}
	}
	return res;
}

void Print(int **arr, std::size_t rows) {
	for (std::size_t i = 0; i < rows; ++i) {
		std::cout << '[' << i << ']';
		for (std::size_t j = 0; j <= i; ++j) {
			std::cout << ' ' << arr[i][j];
		}
		std::cout << '\n';
	}
}

void Deallocate(int **arr, std::size_t rows) {
	// deallocate row arrays
	for (std::size_t i = 0; i < rows; ++i) {
		delete[] arr[i];
	}
	// deallocate the pointer array
	delete[] arr;
}

int main() {
	std::size_t rows;
	std::cout << "Enter the number of rows: " << std::flush;
	std::cin >> rows;
	
	int **pascal = Allocate(rows);
	Print(pascal, rows);
	Deallocate(pascal, rows);
	
	return 0;
}