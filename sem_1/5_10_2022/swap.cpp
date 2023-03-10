#include <iostream>

int main() {
    int a;
    int b;

    std::cin >> a >> b;

    int c = a;
    a = b;
    b = c;

    std::cout << a << " " << b << std::endl;
    return 0;
}