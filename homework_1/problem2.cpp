#include <iostream>
#include <algorithm>
#include <stdexcept>

// клас за Карта Уно
class UnoCard {
	uint8_t color;
	uint8_t value;
	bool	valid = false;

	void errorMessage(unsigned int n) { throw std::runtime_error("[UNO]: INVALID CARD " + std::to_string(n) + " !\n"); }

   public:
	UnoCard() : color(255), value(255){};
	UnoCard(unsigned int n) {
		unsigned int n_cpy = n;

		// извличане на стойности
		n /= 10;
		value = n % 100;
		n /= 10000;
		color = n;

		// валидация на картата
		if (color < 1 || color > 5) {
			errorMessage(n_cpy);
			return;
		}
		if (value > 14) {
			errorMessage(n_cpy);
			return;
		}
		if (value <= 12 && color == 5) {
			errorMessage(n_cpy);
			return;
		}
		if (value >= 13 && color != 5) {
			errorMessage(n_cpy);
			return;
		}
		valid = true;
	}

	// проверка за валидност на картата
	bool good() { return this->valid; }

	// оператор за сравнение
	bool operator<(UnoCard &other) {
		if (value != other.value) return value < other.value;	  // възходяща наредба по стойност
		return color > other.color;								  // и низходяща по цвят
	}

	void print() { std::cout << *this; }

	// оператор за печатане
	friend std::ostream &operator<<(std::ostream &out, UnoCard &card) {
		if (!card.good()) {
			out << "*INVALID CARD*";
			return out;
		}
		out << '(';
		switch (card.color) {
			case 1: out << "YELLOW "; break;
			case 2: out << "GREEN "; break;
			case 3: out << "BLUE "; break;
			case 4: out << "RED "; break;
			case 5: break;
		}
		if (card.value < 10) {
			out << (uint)card.value;
		} else switch (card.value) {
				case 10: out << "+2"; break;
				case 11: out << "REVERSE"; break;
				case 12: out << "STOP"; break;
				case 13: out << "CHANGE COLOR"; break;
				case 14: out << "+4"; break;
			}
		return out << ')';
	}
};

int main() {
	int n;
	std::cin >> n;
	UnoCard *cards = new UnoCard[n];
	// UnoCard cards[10000];

	for (int i = 0; i < n; ++i) {
		unsigned int card;
		std::cin >> card;
		try {
			cards[i] = UnoCard(card);
		} catch (const std::exception &e) {
			std::cerr << e.what();
			return 0;
		}
	}

	std::sort(cards, cards + n);

	for (int i = 0; i < n; ++i) {
		std::cout << cards[i] << ' ';
	}
	std::cout << std::endl;

	delete[] cards;
	return 0;
}

/*
6
123086 200080 123036 523136 323116 523146
*/