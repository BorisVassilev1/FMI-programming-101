#include <iostream>

int main() {
	int a = 5;
	int c = 10;
	int &b = a;
	std::cout << b << '\n';
	b = c;
	std::cout << b << '\n';

	std::cout << a << '\n';
	return 0;
}