#include "pch.h"

TIntNumber2* genArrBin(int size) {
	string str;
	TIntNumber2* M = new TIntNumber2[size];
	
	cout << "Input binary numbers: ";
	for (int i = 0; i < size; i++) {
		cin >> str;
		TIntNumber2 binNumber(str);
		M[i] = binNumber;
	}

	return M;
}

TIntNumber16* genArrHex(int size) {
	string str;
	TIntNumber16* M = new TIntNumber16[size];

	cout << "Input hex numbers: ";
	for (int i = 0; i < size; i++) {
		cin >> str;
		TIntNumber16 binNumber(str);
		M[i] = binNumber;
	}
	cout << '\n';

	return M;
}

TIntNumber2 findSumBin(TIntNumber2* M, int size) {
	TIntNumber2 sum("0");

	cout << "\nYour row: ";
	for (int i = 0; i < size; i++) {
		cout << M[i].getNumber() << " ";

		sum.add(&M[i]);
	}
	cout << "\nDecimal row: ";
	for (int i = 0; i < size; i++) {
		cout << M[i].getDec() << " ";
	}

	cout << "\nDecimal sum: " << sum.getDec();
	cout << "\nBinary sum: " << sum.getNumber();
	cout << '\n';

	return sum;
}
TIntNumber16 findSumHex(TIntNumber16* M, int size) {
	TIntNumber16 sum("0");

	cout << "\nYour row: ";
	for (int i = 0; i < size; i++) {
		cout << M[i].getNumber() << " ";
		
		sum.add(&M[i]);
	}

	cout << "\nDecimal row: ";
	for (int i = 0; i < size; i++) {
		cout << M[i].getDec() << " ";
	}

	cout << "\nDecimal sum: " << sum.getDec();
	cout << "\nHex sum: " << sum.getNumber();

	return sum;
}