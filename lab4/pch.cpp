#include "pch.h"

complx setAttributes1() {
	double p;

	cout << "Input K1:\n";
	cout << "\tinput p>=0: ";
	cin >> p;
	cout << "\tinput fi: "<< p*1.5 << " (as default)\n ";
	cout << "\n";

	complx K1(p);
	
	return K1;
}

complx setAttributes2() {
	double p;
	double fi;

	cout << "Input K2:\n";
	cout << "\tinput p>0: ";
	cin >> p;
	cout << "\tinput fi: ";
	cin >> fi;
	cout << "\n";

	complx K2(p,fi);

	return K2;
}