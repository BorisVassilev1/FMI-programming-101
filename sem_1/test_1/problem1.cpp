#include <iostream>

bool ed(const char n[]) {
	for (int i = 0; n[i] != '\0'; ++i) {
		// ако елементът не е цифра или е нечетна цифра
		if (n[i] > '9' || n[i] < '0' || (n[i] - '0') % 2 == 1) { return false; }
	}
	return true;
}

int main() {
	std::cout << ed("61273") << std::endl;	   // 0
	std::cout << ed("246a") << std::endl;	   // 0
	std::cout << ed("246") << std::endl;	   // 1 защото има само четни цифри
}