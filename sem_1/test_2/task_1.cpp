#include <iostream>

using uint = unsigned int;

bool candidates_goal(uint candidates[], size_t count, uint goal) {
	if(goal == 0) return true;
	if(count == 0) return false;
	for(uint i = 0; i <= goal / candidates[0]; ++ i) {
		if(candidates_goal(candidates + 1, count - 1, goal - i * candidates[0])) {
			return true;
		}
	}
	return false;
}


int main() {
	uint arr [] {5, 3, 12};
	std::cout << candidates_goal(arr, 3, 27) << std::endl;

	std::cout << candidates_goal(arr, 3, 7) << std::endl;

	return 0;
}