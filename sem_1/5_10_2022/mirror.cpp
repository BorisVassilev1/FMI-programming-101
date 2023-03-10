#include <iostream> 

int main() {
    int n;
    std::cin >> n;
    
    int digit1 = n % 10;
    n /= 10;
    int digit2 = n % 10;
    n /= 10;
    int digit3 = n % 10;
    n /= 10;
    int digit4 = n % 10;

    std::cout << digit1 << digit2 << digit3 << digit4 << std::endl;
    return 0;
}