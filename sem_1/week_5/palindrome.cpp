#include <iostream>

int digits[100];

int main() {
    int n;
    std::cin >> n;
    int i = 0;
    for(; n != 0; ++ i) {
        digits[i] = n % 10;
        n /= 10;
    }

    bool isPalindrome = true;
    for(int j = 0; j < i; ++ j) {
        if(digits[j] != digits[i - j - 1])
            isPalindrome = false;
    }
    std::cout << (isPalindrome ? "yes" : "no") << std::endl;
}