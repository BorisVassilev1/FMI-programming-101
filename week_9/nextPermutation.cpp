#include <iostream>

void reverse(int *begin, int *end) {
	--end;
	while (begin < end) {
		std::swap(*begin, *end);
		++begin;
		--end;
	}
}

void nextPermutation(int *begin, int *end) {
	// find longest decreasing suffix
	int *pivot = end - 1;
	while (pivot != begin + 1 && *pivot < *(pivot - 1)) {
		--pivot;
	}
	--pivot;

	// find rightmost successor
	int *successor = end - 1;
	while (successor != begin && *successor <= *pivot) {
		successor--;
	}
	// std::cout << (*successor) << std::endl;
	// std::cout << (*pivot);
	std::swap(*successor, *pivot);

	// reverse suffix
	if (pivot == begin) reverse(pivot, end);
	else reverse(pivot + 1, end);
}

void print(int *begin, int *end) {
	while (begin != end) {
		std::cout << *begin << " ";
		++begin;
	}
}

const int *upper_bound(const int *begin, const int *end, int element) {
	const int *b = begin, *e = end;
	while (b != e) {
		const int *mid = b + (e - b) / 2;

		// std::cout << b - begin << " " << mid - begin << " " << end - begin << std::endl;

		if (*mid <= element) b = mid + 1;
		else e = mid;
	}
	if (b != end) return b;
	return nullptr;
}

bool equal(const int *first_begin, const int *first_end, const int *second_begin, const int *second_end) {
	if (first_end - first_begin != second_end - second_begin) return false;
	while (first_begin != first_end) {
		if (*first_begin != *second_begin) return false;
		++ first_begin;
		++ second_begin;
	}
	return true;
}

void replace(int* begin, int* end, int old_value, int new_value) {
	while(begin != end) {
		if(*begin == old_value)
			*begin = new_value;
		++ begin;
	}
}

int main() {
	// int arr[] =
		// {2, 4, 1, 7, 5, 0};
		// {6, 5, 4, 3, 2, 1};
		// {1, 2, 3, 4, 5, 6};

	// 10:
	// nextPermutation(arr, arr + 6);
	// print(arr, arr + 6);

	// 1:
	// const int *a = upper_bound(arr, arr + 6, 6);
	// if(a != nullptr)
	// 	std::cout << *a;

	// const int arr1[]{1, 2, 1, 3};
	// const int arr2[]{1, 2};
	// std::cout << std::boolalpha << equal(std::begin(arr1), std::begin(arr1) + 2, std::begin(arr2), std::end(arr2))
	// 		  << '\n';	   // -> true
	// std::cout << std::boolalpha
	// 		  << equal(std::begin(arr1) + 2, std::end(arr1), std::begin(arr2), std::end(arr2));	  // -> false

	int arr[]{0, 9, 2, 9, 3, 9};
	replace(std::begin(arr), std::end(arr), 9, 1);
	print(std::begin(arr), std::end(arr)); // -> 0 1 2 1 3 1


}