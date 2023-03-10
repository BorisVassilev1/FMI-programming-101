#include <iostream>
#include <cstring>

using uint = unsigned int;

uint str_to_num(const char *str, size_t last) {
    if(last == 0) {
        return str[0] - '0';
    }
    return str[last] - '0' + 10 * str_to_num(str, last - 1);
}

uint str_to_num(const char *str) {
    return str_to_num(str, strlen(str) - 1);
}

int main() {
    std::cout << str_to_num("1234") << std::endl;
    return 0;
}