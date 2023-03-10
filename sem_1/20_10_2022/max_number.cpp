#include <iostream>

int main() {
	int n, current, max = 0;
	std::cout << "vavedi broi chisla: ";
	std::cin >> n;
	std::cout << "vavedi " << n << "chisla: " << std::endl;

	for (int i = 0; i < n; ++i) {
		std::cin >> current;
		if (current > max) { max = current; }
	}

	std::cout << "Nai-golqmoto chislo e: " << max;
}