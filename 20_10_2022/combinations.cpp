#include <iostream>
#include <cstring>
#include <set>
#include <assert.h>

int coins[] = {1, 2, 5, 10, 20, 50, 100};

int GCD(int a, int b) {
	while (b != 0) {
		int t = b;
		b	  = a % b;
		a	  = t;
	}
	return a;
}

int NOK(int a, int b) { return a * b / GCD(a, b); }

std::set<std::string> answers;

void printState(int count[7]) {
	std::string ans("       ");
	for (int i = 0; i < 7; ++i) {
		std::cout << count[i] << " ";
		ans[i] = count[i];
	}
	answers.insert(ans);
	std::cout << std::endl;
}

int	 allCount = 0;
void printCombinations(int count[7], int step = 1) {
	printState(count);
	allCount++;
	if (step >= 7) return;
	int currCoin = coins[step];
	for (int i = 0; i < step; ++i) {
		int nok = NOK(currCoin, coins[i]);
		for (int j = nok; j <= count[i] * coins[i]; j += nok) {
			int newCount[7];
			memcpy(newCount, count, 7 * sizeof(int));
			newCount[i] -= j / coins[i];
			newCount[step] += j / currCoin;
			printCombinations(newCount, step + 1);
			// printState(newCount);
		}
	}
}

int main() {
	int n;
	std::cin >> n;
	int count[7] = {n, 0, 0, 0, 0, 0, 0};
	printCombinations(count);
	std::cout << "finished!! " << allCount << std::endl;

	std::cout << answers.size() << std::endl;

	return 0;
}