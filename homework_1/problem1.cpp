#include <iostream>
#include <cstring>

// ще работи до 20
void printAsWord(unsigned int n) {
	switch (n) {
		case 1: std::cout << "една";break;
		case 2: std::cout << "две";break;
		case 3: std::cout << "три";break;
		case 4: std::cout << "четири";break;
		case 5: std::cout << "пет";break;
		case 6: std::cout << "шест";break;
		case 7: std::cout << "седем";break;
		case 8: std::cout << "осем";break;
		case 9: std::cout << "девет";break;
		case 10: std::cout << "десет";break;
		case 11: std::cout << "единайсет";break;
		case 12: std::cout << "дванайсет";break;
		case 13: std::cout << "тринайсет";break;
		case 14: std::cout << "четиринайсет";break;
		case 15: std::cout << "петнайсет";break;
		case 16: std::cout << "шестнайсет";break;
		case 17: std::cout << "седенайсет";break;
		case 18: std::cout << "осемнайсет";break;
		case 19: std::cout << "деветнайсет";break;
		case 20: std::cout << "двайсет";break;
	}
}

int main() {
	// брой двойки от елфи
	unsigned int n;
	std::cin >> n;

	unsigned int count = 0;
	for (unsigned int i = 0; i < n; ++i) {
		// секциите на елфите А и Б
		int a_begin, a_end, b_begin, b_end;
		// въвеждаме
		std::cin >> a_begin >> a_end >> b_begin >> b_end;

		if (a_begin > a_end || b_begin < b_end) {
			std::cerr << "Невалидни интервали от секции за елфите!!\n";
			return 0;
		}
		if ((a_begin >= b_begin && a_end <= b_end) ||		// А е подинтервал на Б
			(b_begin >= a_begin && b_end <= a_end)		// Б е подинтервал на А
		) {
			++count;
		}
	}

	if (count == 0) {
		std::cout << "Не се припокриват двойки." << std::endl;
	} else if (count == 1) {
		std::cout << "Припокрива се една двойка." << std::endl;
	} else {
		std::cout << "Припокриват се ";
		printAsWord(count);
		std::cout << " двойки." << std::endl;
	}
	return 0;
}