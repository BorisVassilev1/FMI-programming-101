#include <iostream>

int main() {
	char tempType;
	std::cin >> tempType;
	float input;
	std::cin >> input;
	
	float out;
	if(tempType == 'C') {
		out = (input - 32.f) * 5.f / 9.f;
	} else if(tempType == 'F') {
		out = input * 9.5 / 5.f + 32.f;
	}
	std::cout << out << std::endl;
	return 0;
}