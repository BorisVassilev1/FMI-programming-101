#include <iostream>

int main() {
    int x, y, r;
    std::cin >> x >> y >> r;
    bool res = x*x + y*y <= r*r;
    std::cout << (res ? "YES" : "NO") << std::endl;
}