#include <iostream>

int main() {
    int x1, y1, x2, y2, x3, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    float area = 0.5f * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));

    std::cout << area << std::endl;
}