#include "class.h"
#include "funcs.h"

int main() {
	int size = 0;
	arithmeticProg* arr;

	arr = genArray(size);
	findBiggestSum(arr, size);

	delete[] arr;

	system("pause>0");
}