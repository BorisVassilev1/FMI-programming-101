#include <iostream>

int main() {
    int n;
    std::cin >> n;
    bool res = n == 1 || (n % 4 == 0 && n >= 4);
    std::cout << (res ? "YES" : "NO") << std::endl;
}