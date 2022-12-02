#include <iostream>
#include <iomanip>

using namespace std;

// максимална вместимост на раницата и максимален брой продукти
const int MAXN = 1000;
const int MAXK = 1000;

// стойност и тежест на продуктите
int value[MAXK];
int weight[MAXK];

int dp[2][MAXN];

int n;	   // вместимост на раницата
int k;	   // брой продукти

// принти таблицата
void printdp() {
	for (int j = 0; j < 2; ++j) {
		for (int i = 0; i < n + 1; ++i) {
			// setw от библиотеката iomanip форматира 
			// числото, което печатаме да се заема точно 4 
			// спейса. С твърде големи числа, разбира се, не работи.
			cout << setw(4) << dp[j][i] << " ";
			// пробвайте кода и вижте какво се слиучва
		}
		cout << endl;
	}
}

int main() {
	// въвеждаме си данните
	cin >> n >> k;
	for (int i = 0; i < k; ++i) {
		cin >> weight[i] >> value[i];
	}

	// запълваме първия ред с нули
	for (int i = 0; i < n + 1; ++i) {
		dp[0][i] = 0;
	}

	for (int i = 0; i < k; ++i) {
        // определяме индексите на редовете от масива, в които пишем
		int source = (i) % 2;
        int dest = (i + 1) % 2;

        for (int w = 0; w < n + 1; ++w) {	  // вместимост на по-малката раница
			int maxValue = dp[source][w];
			// проверяваме дали i-тия продукт може да бъде поставен в раницата
			// и да получим повече стойност в раницата
			if (weight[i] <= w) {
				int currValue = dp[source][w - weight[i]] + value[i];
				if (currValue > maxValue) maxValue = currValue;
			}
			dp[dest][w] = maxValue;
		}
	}

	// печатаме цялата таблица
	printdp();

	cout << dp[k % 2][n];

	return 0;
}

/*
6 3
1 10
2 15
3 40
*/