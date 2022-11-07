#include <iostream>
#include <cstring>
#include <assert.h>

/*
    solution of problem 3.16 (3.28?)
*/


const int maxN = 1 << 10;

char s1[maxN];
char s2[maxN];
int len;

char map[26];

void verify() {
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    assert(l1 == l2 && "strings must be the same length");
    len = l1;
}

bool check() {
    for(int i = 0; i < len; ++ i) {
        char indS1 = s1[i] - 'a';
        char indS2 = s2[i];
        if(map[indS1] != 0 && map[indS1] != indS2) return false;
        map[indS1] = indS2;
    }
    return true;
}

int main() {
    std::cin >> s1 >> s2;
    verify();
    std::cout << (check() ? "yes" : "no") << std::endl;
    return 0;
}