#include <iostream>
#include <cmath>

void average() {
	double		 n;
	double		 sum   = 0;
	unsigned int count = 0;
	do {
		std::cin >> n;
		++count;
		sum += n;
		if (n != 0) std::cout << sum / count << '\n';
	} while (n != 0);
}

double pow3(double a) { return a * a * a; }

void cubes(unsigned int n) {
	int i = 1;
	while (pow3(i) < n) {
		std::cout << pow3(i) << '\n';
		++i;
	}
}

void sequence(unsigned int n) {
	for (int i = 1; i <= n; i++) {
		std::cout << 2 * pow3(i) + 3 * i << " ";
	}
	std::cout << std::endl;
}

bool isPrime(unsigned int n) {
	bool prime = true;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			prime = false;
			break;
		}
	}
	return prime;
}

void primeNumbers(unsigned int n) {
	unsigned int count = 0;
	unsigned int num   = 2;
	while (count < n) {
		if (isPrime(num)) {
			std::cout << num << " ";
			++count;
		}
		++num;
	}
	std::cout << std::endl;
}

unsigned int factorial(unsigned int n) {
	unsigned int f = 1;
	for (unsigned int i = 2; i <= n; i++) {
		f *= i;
	}
	return f;
}

unsigned int combinations(unsigned int n, unsigned int k) { return factorial(n) / (factorial(k) * factorial(n - k)); }

bool magicNumber(unsigned int n) {
	unsigned int sum = 0;
	for (unsigned int i = 1; i < n; i++) {
		if (n % i == 0) { sum += i; }
	}
	return n == sum;
}

unsigned int sumOfDigits(unsigned int n) {
	unsigned int sum = 0;
	while (n != 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

void biggestSumOfDigits() {
	unsigned int n;
	unsigned int maxSum = 0;
	unsigned int maxNum = -1;
	while (std::cin >> n) {
		unsigned int sum = sumOfDigits(n);
		if (sum >= maxSum) {
			maxSum = sum;
			maxNum = n;
		}
	}
	std::cout << maxNum << std::endl;
}

unsigned int biggestDigit(int n) {
	unsigned int biggest = 0;
	while (n != 0) {
		unsigned int digit = n % 10;
		if (digit > biggest) biggest = digit;
		n /= 10;
	}
	return biggest;
}

unsigned int smallestDigit(int n) {
	unsigned int smallest = 9;
	while (n != 0) {
		unsigned int digit = n % 10;
		if (digit < smallest) smallest = digit;
		n /= 10;
	}
	return smallest;
}

void predicates(int n) {
	unsigned int count = 0;
	unsigned int i	   = 2;
	while (count < n) {
		unsigned int diff = biggestDigit(i) - smallestDigit(i);
		unsigned int sum  = sumOfDigits(i);
		if (isPrime(sum) && diff == 3) {
			std::cout << i << " ";
			++count;
		}
		++i;
	}
	std::cout << std::endl;
}

int main() {
	unsigned int n;
	std::cin >> n;
	predicates(n);
}