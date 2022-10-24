#include <iostream>
#include <iomanip>

int main () {
	int a;
	float b;
	std::cin >> a >> b;
	std::cout << std::setprecision(3) << std::endl;
	std::cout << a << " " << b << std::endl;
}