#include <iostream>
#include <cstring>

bool isSign(char a) { return a == '.' || a == ',' || a == '?' || a == '!' || a == '*' || a == '$'; }

bool isLetter(char a) { return (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'); }

int main() {
	char src[255];

	std::cin.getline(src, 255);

	int	 spaceCount	 = 0;
	int	 letterCount = 0;
	bool endOfWord	 = false;
	bool beginWord	 = false;
	for (int i = 0; src[i] != 0; ++i) {
		if (src[i] == ' ') {
			++spaceCount;
		} else spaceCount = 0;

		endOfWord = false;
		beginWord = false;
		if (isLetter(src[i])) {
			if (letterCount == 0) beginWord = true;
			++letterCount;
		} else {
			if (letterCount != 0) endOfWord = true;
			letterCount = 0;
		}

		if (beginWord && i != 0) std::cout << ' ';

		if (spaceCount == 0) std::cout << src[i];
	}
	std::cout << std::endl;
}