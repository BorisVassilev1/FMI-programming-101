#include <iostream>

using std::cout, std::cin, std::endl;
using uint = uint32_t;

uint digitCount(uint n) {
	uint c = 0;
	while (n != 0) {
		n /= 10;
		++c;
	}
	return c;
}

bool hasRepeatingDigits(uint n) {
	if (n == 0) return false;
	uint tempn;
	while (n) {
		tempn = n / 10;
		while (tempn) {
			if (tempn % 10 == n % 10) { return true; }
			tempn /= 10;
		}
		n /= 10;
	}
	return false;
}

uint filterNumber(uint n, uint mask) {
	uint result = 0;
	uint exp	= 1;
	while (n != 0) {
		bool bit = mask & 1;
		if (bit) {
			result += exp * (n % 10);
			exp *= 10;
		}
		n /= 10;
		mask >>= 1;
	}
	return result;
}

int main() {
	uint n;
	cin >> n;
	uint sum = 0;

	uint digits	 = digitCount(n);
	uint maxMask = 1 << digits;
	uint mask	 = 1;
	while (mask < maxMask) {
		int curr = filterNumber(n, mask);
		if (!hasRepeatingDigits(curr)) { sum += curr; }
		++mask;
	}
	cout << sum;
	return 0;
}