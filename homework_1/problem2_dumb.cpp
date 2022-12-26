#include <iostream>
#include <algorithm>

using uchar = unsigned char;

uchar getColor(const uint card) { return (double)card * ( 1./ 100000); }
uchar getValue(const uint card) { return (int)((double)card * (1./ 10)) % 100; }

bool validate(const uint card) {
	const uchar color = getColor(card);
	const uchar value = getValue(card);
	
	// валидация на картата
	if (color < 1 || color > 5) { return false; }
	if (value > 14) { return false; }
	if (value <= 12 && color == 5) { return false; }
	if (value >= 13 && color != 5) { return false; }
	return true;
}

bool compare(const uint card1, const uint card2) {
	const uchar val1 = getValue(card1);
	const uchar val2 = getValue(card2);
	if (val1 != val2) return val1 < val2;		  // възходяща наредба по стойност
	return getColor(card1) > getColor(card2);	  // и низходяща по цвят
}

void printCard(const uint card) {
		const uchar color = getColor(card);
		const uchar value = getValue(card);
		
		std::cout << '(';
		switch (color) {
			case 1: std::cout << "YELLOW "; break;
			case 2: std::cout << "GREEN "; break;
			case 3: std::cout << "BLUE "; break;
			case 4: std::cout << "RED "; break;
			case 5: break;
		}
		if (value < 10) {
			std::cout << (uint)value;
		} else switch (value) {
				case 10: std::cout << "+2"; break;
				case 11: std::cout << "REVERSE"; break;
				case 12: std::cout << "STOP"; break;
				case 13: std::cout << "CHANGE COLOR"; break;
				case 14: std::cout << "+4"; break;
			}
		std::cout << ')';
}

int main() {
	uint n;
	std::cin >> n;
	uint *cards = new uint[n];
	
	for(uint i = 0; i < n; ++ i) {
		std::cin >> cards[i];
		if(!validate(cards[i])) {
			std::cerr << "INVALID CARD: " << cards[i] << "\n";
			return 0;
		}
	}

	std::sort(cards, cards + n, compare);
	
	for(uint i = 0; i < n; ++ i) {
		printCard(cards[i]);
		std::cout << ' ';
	}
	std::cout << std::endl;

	delete[] cards;
	return 0;
}

/*
6
123086 200080 123036 523136 323116 523146
*/