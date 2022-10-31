#include <iostream>
#include <cstring>
/*
	solution of problem 3.15
*/

const int maxN = 1 << 10;

char source[maxN] =
	"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Praesent sagittis eu metus gravida tristique. Praesent "
	"neque felis, tempor ac lobortis sed, lacinia vel arcu. Aliquam consectetur metus non bibendum gravida. "
	"Suspendisse ornare tortor eget sollicitudin dictum. Morbi id ipsum et nibh accumsan feugiat. Cras pulvinar eget "
	"nisi nec molestie. Nulla at elit lectus. Fusce suscipit elit lorem, vel sollicitudin risus imperdiet vitae. "
	"Vestibulum posuere felis erat, nec suscipit ipsum pharetra at.";
char pattern[maxN] = "is";
int	 lps[maxN];
int	 patternLen;
int	 sourceLen;

void computeLPS() {
	int counter = 0;
	for (int i = 0; i < patternLen; ++i) {
		if (i != counter && pattern[i] == pattern[counter]) ++counter;
		else counter = 0;
		lps[i] = counter;
	}
}

bool search() {
	int	 i = 0, j = 0;
	bool res = false;
	while (i < sourceLen) {
		if (source[i] == pattern[j]) {
			++i;
			++j;
			if (j == patternLen) {
				res = true;
				std::cout << "match at position: " << i - j << std::endl;
			}
		} else {
			if (j == 0) ++i;
			else j = lps[j - 1];
		}
	}
    return res;
}

int main() {
	// std::cin >> source >> pattern;
	patternLen = strlen(pattern);
	sourceLen  = strlen(source);

	computeLPS();
	std::cout << (search() ? "FOUND A MATCH!" : "NO MATCHES!") << std::endl;

	return 0;
}