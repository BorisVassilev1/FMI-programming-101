#include <iostream>
#include "vector.hpp"

int main() {
	vector<int> vec1;
	vec1.push(1);
	vec1.push(2);
	vec1.push(3);
	vec1.push(4);

	vector<int> vec2;
	vec2.push(5);
	vec2.push(6);
	vec2.push(7);
	vec2.push(8);

    vec1 += vec2;

    vector<int> vec3 = vec1 + vec2;

	std::cout << vec3 << std::endl;
    std::cout << vec3.substr(2, 4) << std::endl;
    std::cout << (int*) vec3 << std::endl;
    return 0;
}