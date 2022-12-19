#include <iostream>

int main() {
	// едномерен масив
	int *arr = new int[10];
	delete [] arr;
	
	// не можем лесно да заделим двумерен масив
	// правим масив от int*, всеки от които е масив.
	int **mat = new int*[10];
	for(int i = 0; i < 10; ++ i)
		mat[i] = new int[10];


	// триенето е съшо с цикъл
	for(int i = 0; i < 10; ++ i)
		delete [] mat[i];
	delete [] mat;

}