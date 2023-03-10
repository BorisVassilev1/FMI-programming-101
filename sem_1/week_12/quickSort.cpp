#include <iostream>

void print(int *begin, int *end) {
	while(begin != end) {
		std::cout << *begin << " ";
		++ begin;
	}
	std::cout << std::endl;
}

int *partition(int *begin, int *end, int pivot) {
	while(begin != end) {
		if(*begin > pivot) {
			std::iter_swap(begin, end - 1);
			-- end;
		}else {
			++ begin;
		}
	}
	return begin;
}

void quickSort(int *begin, int *end) {
	if(begin == end) {
		return;
	}
	int *mid = partition(begin, end, *begin);
	std::iter_swap(begin, mid - 1);
	quickSort(begin, mid - 1);
	quickSort(mid, end);
}

int main() {
	int arr[] {5,9,6,1,7,8,3,2,4,0};
	print(arr, arr + 10);
	quickSort(arr, arr + 10);
	print(arr, arr + 10);
}