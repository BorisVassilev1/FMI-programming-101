#include <iostream>
#include <iomanip>

using namespace std;
const int max_n = 10;

void inputMatrix(float matrix[][max_n + 1], unsigned int n) {
	for (unsigned int i = 0; i < n; ++i) {
		for (unsigned int j = 0; j < n + 1; ++j) {
			cin >> matrix[i][j];
		}
	}
}

void printMatrix(float matrix[][max_n + 1], unsigned int n) {
	for (unsigned int i = 0; i < n; ++i) {
		for (unsigned int j = 0; j < n + 1; ++j) {
			cout << setw(3) << matrix[i][j] << ' ';
		}
		cout << '\n';
	}
}

// prints answers like x1 = 10; x2 = 5 ...
void printAnswers(float matrix[][max_n + 1], unsigned int n) {
	for (unsigned int i = 0; i < n; ++i) {
		cout << "x" << i << " = " << setw(4) << matrix[i][n] << '\n';
	}
}

// swaps the i-th and j-th row of the matrix
void swapRows(float matrix[][max_n + 1], unsigned int n, unsigned int i, unsigned int j) {
	for (unsigned int k = 0; k < n + 1; ++k) {
		std::swap(matrix[i][k], matrix[j][k]);
	}
}

// adds the j-th row, multiplied by coef to the i-th row
void addRows(float matrix[][max_n + 1], unsigned int n, unsigned int i, unsigned int j, float coef) {
	for (unsigned int k = 0; k < n + 1; ++k) {
		matrix[i][k] += matrix[j][k] * coef;
	}
}

// multiplies the i-th row by coef
void multRow(float matrix[][max_n + 1], unsigned int n, unsigned int i, float coef) {
	for (unsigned int k = 0; k < n + 1; ++k) {
		matrix[i][k] *= coef;
	}
}

void gauss(float matrix[][max_n + 1], unsigned int n) {
	for (unsigned int i = 0; i < n; ++i) {
		// eliminate variable x_i

		// check for zero in the main diagonal
		if (matrix[i][i] == 0) {
			// find a row without a zero in that place
			for (unsigned int k = 0; k < n; ++k) {
				if (matrix[k][i] != 0) {
					swapRows(matrix, n, i, k);
					break;
				}
			}
			--i;
			continue;
		}
		// make sure there is a 1 on the main diagonal
		multRow(matrix, n, i, 1. / matrix[i][i]);

		// eliminate everything in the column
		for (unsigned int j = 0; j < n; ++j) {
			if (j == i) continue;
			addRows(matrix, n, j, i, -matrix[j][i]);
		}
	}
}

int main() {
	unsigned int n;
	cin >> n;

	float matrix[max_n][max_n + 1];
	inputMatrix(matrix, n);
	gauss(matrix, n);
	printAnswers(matrix, n);
	
	return 0;
}

/*
3
1  1  1  8
1 -2  1  5
1  1 -1 -4

4
 4  1  2 -3    -16
-3  3 -1  4     20
-1  2  5  1    -4
 5  4  3 -1    -10
*/
