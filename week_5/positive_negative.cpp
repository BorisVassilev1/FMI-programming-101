#include <iostream>

using std::cin;
using std::cout;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i > j) cout << '-';
			else if (i < j) cout << '+';
			else cout << '0';
		}
		cout << '\n';
	}
}