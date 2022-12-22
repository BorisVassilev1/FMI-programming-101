#include <iostream>
#include <iomanip>

using uint = unsigned int;

static constexpr size_t MAX_LEN = 255;

template <class T>
void printMatrix(T canvas[][255], size_t height, size_t width) {
	for (size_t i = 0; i < height; ++i) {
		for (size_t j = 0; j < width; ++j) {
			std::cout << std::setw(3) << canvas[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

bool find_word(char matrix[][MAX_LEN], size_t rows, size_t cols, char *word, size_t x, size_t y,
			   bool visited[][MAX_LEN]) {
	if (!*word) { return true; }
	if (x >= rows || y >= cols || *word != matrix[x][y] || visited[x][y]) { return false; }
	visited[x][y] = true;
	// return (find_word(matrix, rows, cols, word + 1, x + 1, y, visited) ||
	// 		find_word(matrix, rows, cols, word + 1, x - 1, y, visited) ||
	// 		find_word(matrix, rows, cols, word + 1, x, y + 1, visited) ||
	// 		find_word(matrix, rows, cols, word + 1, x, y - 1, visited)) &&
	// 	   (visited[x][y] = false);

	bool res = false;
	res = res || find_word(matrix, rows, cols, word + 1, x + 1, y, visited);
	res = res || find_word(matrix, rows, cols, word + 1, x - 1, y, visited);
	res = res || find_word(matrix, rows, cols, word + 1, x, y + 1, visited);
	res = res || find_word(matrix, rows, cols, word + 1, x, y - 1, visited);
	visited[x][y] = false;
	return res;
}

unsigned crossword(char matrix[][MAX_LEN], size_t rows, size_t cols, char words[][MAX_LEN], size_t n) {
	bool visited[MAX_LEN][MAX_LEN]{};
	uint counter = 0;

	for (uint i = 0; i < n; ++i) {
		for (uint j = 0; j < rows; ++j) {
			for (uint k = 0; k < cols; ++k) {
				if (find_word(matrix, rows, cols, words[i], j, k, visited)) {
					++counter;
					std::cout << words[i] << std::endl;
				}
				// printMatrix(visited, rows, cols);
				// std::cout << std::endl;
			}
		}
	}

	return counter;
}

int main() {
	char matrix[][255] = {{'c', 'a', 't'}, {'w', 'h', 'o'}, {'w', 'i', 'n'}};
	char words[][255]  = {"cat", "hello", "what", "caca"};
	std::cout << crossword(matrix, 3, 3, words, 4) << std::endl;		// -> 2
	return 0;
}