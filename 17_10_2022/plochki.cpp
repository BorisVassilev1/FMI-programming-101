#include <iostream>

int main() {
	int m, n, a;
	std::cin >> m >> n >> a;
	int res = (m / a + (m % a != 0)) * (n / a + (n % a != 0));
	std::cout << res << std::endl;
}