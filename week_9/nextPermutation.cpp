#include <iostream>

void reverse(int *begin, int *end) {
	// end must point to the last element
	--end;
	// the rest is simple
	while (begin < end) {
		std::swap(*begin, *end);
		++begin;
		--end;
	}
}

bool next_permutation(int *begin, int *end) {
	// find longest decreasing suffix
	int *pivot = end - 1;
	while (pivot != begin && *pivot < *(pivot - 1)) {
		--pivot;
	}
	if(pivot == begin) {
		reverse(begin, end);
		return false;
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
	reverse(pivot + 1, end);
	return true;
}

void print(const int *begin, const int *end) {
	while (begin != end) {
		std::cout << *begin << " ";
		++begin;
	}
}

const int *upper_bound(const int *begin, const int *end, int element) {
	// classic binary search. !!I missed the mid + 1.
	const int *b = begin, *e = end;
	while (b != e) {
		const int *mid = b + (e - b) / 2;

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
		++first_begin;
		++second_begin;
	}
	return true;
}

void replace(int *begin, int *end, int old_value, int new_value) {
	while (begin != end) {
		if (*begin == old_value) *begin = new_value;
		++begin;
	}
}

void rotate(int *begin, int *mid, int *end) {
	// inefficient, but simple and with 2n complexity. Can't get much better
	reverse(begin, mid);
	reverse(mid, end);
	reverse(begin, end);
}

const int *search(const int *first_begin, const int *first_end, const int *second_begin, const int *second_end) {
	// IM NOT IMPLEMENTING KMP FOR NUMBERS. it is only efficient for strings
	for (const int *i = first_begin; i < first_end; ++i) {
		bool same = true;
		for (const int *j = second_begin; j < second_end; ++j) {
			if (*(i + (j - second_begin)) != *j) {	   // a little inefficient, but saves a line or two
				same = false;
				break;
			}
		}
		if (same) return i;
	}
	return nullptr;
}

bool ends_with(const int *first_begin, const int *first_end, const int *second_begin, const int *second_end) {
	if (first_end - first_begin < second_end - second_end) { return false; }
	--first_end;
	--second_end;
	while (second_end > second_begin) {
		if (*second_end != *first_end) { return false; }
		--first_end;
		--second_end;
	}
	return true;
}

const int *find_end(const int *first_begin, const int *first_end, const int *second_begin, const int *second_end) {
	int first_len  = first_end - first_begin;
	int second_len = second_end - second_begin;
	if (first_len < second_len) return 0;
	for (int i = first_len - second_len; i >= 0; --i) {
		bool same = true;
		for (int j = 0; j < second_len; ++j) {
			if (first_begin[i + j] != second_begin[j]) {
				same = false;
				break;
			}
		}
		if (same) return first_begin + i;
	}
	return nullptr;
}

int *unique(int *begin, int *end) {
	int offset = 1;
	for (int *i = begin + 1; i != end; ++i) {
		if (*i == *(i - offset)) {		  // if it is the same as the previous
			++offset;					  // then don't look at the element again
		} else {						  // if they are different
			*(i - offset + 1) = *(i);	  // copy the next second element right after the first
		}
	}
	return end - offset + 1;
}

int *partition(int *begin, int *end) {
	if (begin == end) return begin;
	while (begin != end) {
		if (*begin % 2 == 0) {
			std::swap(*begin, *(end - 1));
			--end;
		} else {
			++begin;
		}
	}
	return begin;
}

int main() {

	// 1:
	// const int arr[]{0, 1, 2, 5};
	// const int *element = upper_bound(std::begin(arr), std::end(arr), 4);
	// const int *notFound = upper_bound(std::begin(arr), std::begin(arr) + 2, 4);

	// element ? std::cout << *element << '\n' : std::cout << "There are no bigger elements than 4\n"; // -> 5
	// notFound ? std::cout << *notFound << '\n' : std::cout << "There are no bigger elements than 4\n"; // -> There are
	// no bigger elements than 4

	// 2:
	// const int arr1[]{1, 2, 1, 3};
	// const int arr2[]{1, 2};
	// std::cout << std::boolalpha << equal(std::begin(arr1), std::begin(arr1) + 2, std::begin(arr2), std::end(arr2))
	// 		  << '\n';	   // -> true
	// std::cout << std::boolalpha
	// 		  << equal(std::begin(arr1) + 2, std::end(arr1), std::begin(arr2), std::end(arr2));	  // -> false

	// 3:
	// int arr[]{0, 9, 2, 9, 3, 9};
	// replace(std::begin(arr), std::end(arr), 9, 1);
	// print(std::begin(arr), std::end(arr)); // -> 0 1 2 1 3 1

	// 4:
	// int arr[]{0, 1, 2, 3, 4};
	// rotate(std::begin(arr), std::begin(arr) + 2, std::end(arr));
	// print(std::begin(arr), std::end(arr));	   // -> 2 3 4 0 1

	// 5:
	// const int  arr[]{0, 1, 2, 1, 2};
	// const int  seq[]{1, 2};
	// const int *begin = search(std::begin(arr), std::end(arr), std::begin(seq), std::end(seq));
	// print(begin, std::end(arr));	 // -> 1 2 1 2

	// 6:
	// const int arr[]{2, 4, 5, 3, 7, 6};
	// const int arr2[]{7, 6};
	// std::cout << std::boolalpha << ends_with(std::begin(arr), std::end(arr), std::begin(arr2), std::end(arr2))
	// 		  << '\n';	   // -> true
	// std::cout << std::boolalpha
	// 		  << ends_with(std::begin(arr), std::begin(arr) + 5, std::begin(arr2), std::end(arr2));		// -> false

	// 7:
	// const int arr[]{0, 1, 2, 1, 2, 5};
	// const int seq[]{1, 2};
	// const int* begin = find_end(std::begin(arr), std::end(arr), std::begin(seq), std::end(seq));
	// print(begin, std::end(arr)); // -> 1 2 5

	// 8:
	// int	 arr[]{1, 2, 1, 1, 3, 3, 3, 4, 4, 5, 4};
	// int *end = unique(std::begin(arr), std::end(arr));
	// print(std::begin(arr), end);	 // -> 1 2 1 3 4 5 4

	// 9:
	// int	 arr[]{4, 7, 1, 3, 2, 6, 5, 9, 0};
	// int *evenBegin = partition(std::begin(arr), std::end(arr));
	// print(std::begin(arr), evenBegin);	   // -> 7 1 3 5 9
	// std::cout << '\n';
	// print(evenBegin, std::end(arr));	 // -> 4 2 6 0

	// 10:
	int arr[] =
	// {2, 4, 1, 7, 5, 0};
	// {6, 5, 4, 3, 2, 1};
	{1, 2, 3, 4, 5, 6};

	do {
		print(std::begin(arr), std::end(arr));
		std::cout << std::endl;
	} while (next_permutation(std::begin(arr), std::end(arr)));

	return 0;
}