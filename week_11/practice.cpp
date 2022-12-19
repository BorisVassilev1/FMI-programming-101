#include <iostream>

int sumInterval(int a, int b) {
	if(a == b) return a;
	return a + sumInterval(a + 1, b);
}

unsigned countDigits(unsigned n) {
	if(n == 0) return 0;
	return countDigits(n / 10) + 1;
}

unsigned gcdRec(int a, int b) {
	if(a == 0) {
		return b;
	}
	
	int r = b % a;
	return gcdRec(r, a);
}

double quickPow(double x, int n) {
	if(n == 0) return 1;
	if(n < 0) return quickPow(1/x, -n);

	if(n % 2 == 0) {
		return quickPow(x * x, n / 2);
	}
	else {
		return x * quickPow(x, n -1);
	}
}

void print(const int *begin, const int *end) {
	if(begin == end) return;
	std::cout << *begin << ' ';
	print(++ begin, end);
}

const int* findFirstEven(const int* begin, const int* end) {
	if(begin == end) return nullptr;
	if(*begin % 2 == 0) return begin;
	return findFirstEven(++begin, end);
}

bool isSorted(const int* begin, const int* end) {
	if(begin == end - 1) return true;
	if(*begin < *(begin + 1)) {
		return isSorted(++begin, end);
	}
	return false;
}

bool isPalindrome(const int* begin, const int* end) {
	if(begin == end - 1 || begin == end) return true;
	if(*begin == *(end - 1)) {
		return isPalindrome(++begin, --end);
	}
	return false;
}

const int* lower_bound(const int* begin, const int* end, int element) {
	if(begin == end) return nullptr;
	if(*begin >= element) {
		return begin;
	}
	return lower_bound(++begin, end, element);
}

void printReverse(const int* begin, const int* end) {
	if(begin == end) return;
	std::cout << *(end - 1) << ' ';
	printReverse(begin, end - 1);
}

int maxRepeated_(const int *begin, const int *end, int currElem, int seqLen, int maxSeqLen) {
	if(begin == end) return maxSeqLen;
	if(*begin != currElem) {
		return maxRepeated_(begin + 1, end, *begin, 1, seqLen > maxSeqLen ? seqLen : maxSeqLen);
	}
	return maxRepeated_(begin + 1, end, currElem, ++seqLen, maxSeqLen);
}

int maxRepeated(const int* begin, const int* end) {
	return maxRepeated_(begin, end, *begin, 0, 0);
}

bool isDigit(char a) {
	return a >= '0' && a <= '9';
}

int stoi(const char *&source, int val = 0) {
	if(!*source) return val;
	if(!isDigit(*source)) return val;
	val *= 10;
	val += *source - '0';
	return stoi(++source, val);
}

int *extractEvens(const char *source, int *destination) {
	if(!*source) return destination;
	if(isDigit(*source)) {
		int num = stoi(source);
		if(num % 2) return extractEvens(++source, destination);
		*destination = num;
		return extractEvens(++ source, ++destination);
	}
	else return extractEvens(++ source, destination);
}

void towersOfHanoi(unsigned n, char rod1, char rod2, char rod3) {
	if(n == 1) {
		std::cout << "MOVE disk 1 from rod " << rod1 << " to " << rod3 << std::endl;
		return;
	}
	// move top n-1 from 1 to 2
	towersOfHanoi(n-1, rod1, rod3, rod2);
	// move the bottom-most from 1 to 3;
	std::cout << "MOVE disk " << n << " from rod " << rod1 << " to " << rod3 << std::endl;
	// move all other from 2 to 3
	towersOfHanoi(n-1, rod2, rod1, rod3);
}

int main() {
	// 1
	// std::cout<<sumInterval(1, 10); // -> 55
	
	// 2
	// std::cout<<countDigits(42891); // -> 5

	// 3
	// std::cout<<gcdRec(72, 90); // -> 18

	// 4
	// std::cout<<quickPow(3, 6); // -> 729

	// 5
	// const int arr[] {5, 7, 13, 3, 6, 23, 17};
	// const int* firstEven = findFirstEven(std::begin(arr), std::end(arr));
	// print(firstEven, std::end(arr)); // -> 6 23 17

	// 6
	// const int arr1[] {4, 7, 11, 16, 24};
	// const int arr2[] {4, 7, 5, 11, 18};
	// std::cout<<std::boolalpha<<isSorted(std::begin(arr1), std::end(arr1))<<'\n'; // -> True
	// std::cout<<isSorted(std::begin(arr2), std::end(arr2))<<'\n'; // -> False

	// 7
	// const int arr1[] {4, 7, 11, 7, 4};
	// const int arr2[] {4, 7, 11, 11, 7, 4};
	// std::cout<<std::boolalpha<<isPalindrome(std::begin(arr1), std::end(arr1))<<'\n'; // -> True
	// std::cout<<std::boolalpha<<isPalindrome(std::begin(arr2), std::end(arr2))<<'\n'; // -> False

	// 8
	// const int arr[]{6, 7, 9, 10, 12, 15};
	// const int *lower = lower_bound(std::begin(arr), std::end(arr), 12);
	// if (lower)
	// {
	// 	print(lower, std::end(arr));
	// }
	// else
	// {
	// 	std::cout << "No such element\n";
	// }
	// // -> 12 15

	// 9
	// const int arr[] {5, 7, 4, 10, 6, 0};
	// printReverse(std::begin(arr), std::end(arr)); // -> 0 6 10 4 7 5

	// 10
	// const int arr[] {1, 1, 2, 3, 3, 3, 4, 2, 2, 2, 2, 1, 1};
	// std::cout<<maxRepeated(std::begin(arr), std::end(arr)); // -> 4

	// 11
	// int arr[255]{};
	// int *evensEnd = extractEvens("458sade21asd4asd42a7sd8", arr); // -> 458 4 42 8
	// print(std::begin(arr), evensEnd);

	// 12
	// towersOfHanoi(1, 'A', 'B', 'C');
	// towersOfHanoi(2, 'A', 'B', 'C');
	towersOfHanoi(3, 'A', 'B', 'C');

	return 0;
}