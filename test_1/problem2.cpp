#include <iostream>

bool isHill(int n, int arr[]) {
	bool hasReachedHill = false;
	for (int i = 0; i < n - 1; ++i) {
		// проверка дали сме стигнали втората половина
		if (arr[i] > arr[i + 1]) {
			hasReachedHill = true;
		}
		// ако сме във втората половина, а(i+1) > ai е 'нелегално'
		if (hasReachedHill && arr[i] < arr[i + 1]) {
			return false;
		}
	}
	return true;
}

int main() {
	// тестове
	// 6
	// 1 2 3 4 5 6
	// -> 1

	// 6
	// 1 2 3 3 2 1
	// -> 1

	// 6
	// 1 2 3 1 0 6
	// -> 0

	// исканата задача с въвеждане от стандартния вход
	int n;
	std::cin >> n;
	// за да работи за всяко N, заделяме паметта динамично
	int *arr = new int[n];
	for (int i = 0; i < n; ++i) {
		std::cin >> arr[i];
	}
	// печатаме отговора
	std::cout << isHill(n, arr) << std::endl;

	delete[] arr;
}