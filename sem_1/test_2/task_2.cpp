#include <iostream>
const int MAX_M = 256;

// [] ama za indeksirane na diagonal na matricata
//   0\   1\  2\  3\
//      0   0   0   0
//   4\
//      0   0   0   0
//   5\
//      0   0   0   0
//   6\
//      0   0   0   0
// ako tuk nulite sa matricata, sa nomerirani kakto e pokazano
int &indexDiagonal(int mat[][MAX_M], size_t m, size_t diagonal, size_t i) {
    if(diagonal < m) {
        return mat[i][diagonal + i];
    } else {
        return mat[2 * m - diagonal + i - 1][i];
    }
}

// dyljina na diagonal s nomer
size_t diagonalLength(size_t m, size_t diagonal) {
    if(diagonal < m) {
        return m-diagonal;
    } else {
        return diagonal - m + 1;
    }
}

// sortira diagonal na matricata s bubble sort :)
void sortDiagonal(int mat[][MAX_M], size_t m, size_t d) {
    size_t len = diagonalLength(m, d);
    for(size_t i = 0; i < len - 1; ++ i) {
        for(size_t j = 0; j < len - i - 1; ++ j) {
            int &a = indexDiagonal(mat, m, d, j);
            int &b = indexDiagonal(mat, m, d, j + 1);
            if(a > b) {
                std::swap(a, b);
            }
        }
    }
}

// sortira vsichkite diagonali na matricata
void diagonals(int mat[][MAX_M], size_t m) {
    for(size_t i = 0; i < 2 * m - 1; ++ i) {
        sortDiagonal(mat, m, i);
    }
    std::cout << std::endl;
}

void print(int mat[][MAX_M], size_t m) {
    for(size_t i = 0; i < m; ++ i) {
        for(size_t j = 0; j < m; ++ j) {
            std::cout << mat[i][j] << ' ';
        }
        std::cout << '\n';
    }
} 

int main() {
    int mat[][MAX_M] {
        {3,3,1,1},
        {2,2,1,2},
        {1,1,1,2},
        {2,3,2,1}
    };

	diagonals(mat, 4);

    print(mat, 4);

	return 0;
}