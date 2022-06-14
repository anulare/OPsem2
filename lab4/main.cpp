#include "pch.h"

int main() {
	complx K1 = setAttributes1();
	complx K2 = setAttributes2();
	complx K3;
	
	cout << "K1 ";
	K1.ind();
	K1.alg();
	cout << '\n';

	cout << "K2 ";
	K2.ind();
	K2.alg();

	cout << "\nK1 ";
	++K1;
	K1.alg();

	cout << "\nK2 ";
	K2++;
	K2.alg();

	cout << "\n";
	K3 = K1 + K2;
	cout << '\n';
	K3.alg();
	
	int a = 0, b = 1;

}