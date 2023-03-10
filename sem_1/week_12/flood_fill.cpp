#include <iostream>
#include <iomanip>

void printMatrix(int canvas[][255], size_t height, size_t width) {
	for (size_t i = 0; i < height; ++i) {
		for (size_t j = 0; j < width; ++j) {
			std::cout << std::setw(3) << canvas[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void flood_fill(int canvas[][255], size_t height, size_t width, size_t x, size_t y, int color, int initialColor) {
	if (x >= width || y >= height) { return; }
	if (canvas[x][y] == initialColor) {
		canvas[x][y] = color;
		flood_fill(canvas, height, width, x + 1, y, color, initialColor);
		flood_fill(canvas, height, width, x - 1, y, color, initialColor);
		flood_fill(canvas, height, width, x, y + 1, color, initialColor);
		flood_fill(canvas, height, width, x, y - 1, color, initialColor);
	}
}

void flood_fill(int canvas[][255], size_t height, size_t width, size_t x, size_t y, int color) {
	flood_fill(canvas, height, width, x, y, color, canvas[x][y]);
}

int main() {
	int canvas[][255]{
		{4, 2, 3, 2, 6},
		{5, 2, 2, 7, 10},
		{2, 2, 8, 2, 1},
		{9, 2, 2, 2, 3},
	};

	flood_fill(canvas, 4, 5, 1, 1, 20);
	printMatrix(canvas, 4, 5);
}