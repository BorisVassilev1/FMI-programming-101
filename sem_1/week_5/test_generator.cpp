#include <iostream>
#include <cassert>
#include <fstream>
#include <random>
#include <ctime>

using namespace std;

int main() {
    const int n = 1e7;
    

    std::ofstream out("test.txt");

    out << n << std::endl;
    for(uint i = 0; i < n; ++ i) {
        out << (rand() << 16 | rand()) << " ";
    }
}