#include <iostream>
#include <functional>

int main() {
	int a, b;
	std::cin >> a >> b;

	std::function<void(int, int, int&)> sumABInternal = [&](int i, int max, int& sum) -> void {
		sum += i;
		++i;
		if (i > max) return;
		sumABInternal(i, max, sum);
	};

	std::function<int(int, int)> sumAB = [&](int a, int b) -> int {
		int res = 0;
		sumABInternal(a, b, res);
		return res;
	};

	std::cout << sumAB(a, b) << std::endl;
}
