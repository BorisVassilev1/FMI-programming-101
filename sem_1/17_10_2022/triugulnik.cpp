#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    if(a <= 0 || b <= 0 || c <= 0) {
        std::cout << "NEVALIDEN VHOD";
        return 0;
    }

    bool result = (a + b > c) && (b + c > a) && (c + a > b);

    std::cout << result ? "da" : "ne";
}