#include "class.h"

void arithmeticProg::setA() {
	double valueA;

	cout << "Set first member a = ";
	cin >> valueA;

	a = valueA;
}

void arithmeticProg::setD() {
	double valueD;

	cout << "Set difference d = ";
	cin >> valueD;

	d = valueD;
}

void arithmeticProg::setN() {
	int valueN;

	cout << "Set amount n = ";
	cin >> valueN;

	n = valueN;
}

double arithmeticProg::getA() {
	return this->a;
}
double arithmeticProg::getD() {
	return this->d;
}
int arithmeticProg::getN() {
	return this->n;
}


double arithmeticProg::getSum() {
	sum = (2*a + d*(n-1))*n / 2;

	return sum;
}