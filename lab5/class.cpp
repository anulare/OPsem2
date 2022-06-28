#include "pch.h"

int TIntNumber::getDec() {
	return dec;
}
string TIntNumber::getNumber() {
	return number;
}


TIntNumber2::TIntNumber2(string number) {			// конструктор для класу TIntNumber2
	this->number = number;
	this->system = 2;
}
TIntNumber2::TIntNumber2() {
	this->system = 2;
}

TIntNumber16::TIntNumber16(string number) {			// конструктор для класу TIntNumber16
	this->number = number;
	this->system = 16;
}
TIntNumber16::TIntNumber16() {
	this->system = 16;
}



void TIntNumber2::changeSystem(int sys) {
	if (this->system == 2 && sys == 10) {

		int dec = 0;

		for (int i = 0; i < number.length(); i++) {
			if (number[number.length() - i - 1] == '1') {
				dec += pow(2, i);
			}
		}
		this->dec = dec;

		this->system = 10;
	}
	else if (this->system == 10 && sys == 2) {

		string bin;
		int whole = this->dec;
		int rest;

		do {
			rest = whole % 2;
			whole /= 2;

			bin = to_string(rest) + bin;
		} while (whole);
		this->number = bin;

		this->system = 2;
	}
}
void TIntNumber16::changeSystem(int sys) {
	if (this->system == 10 && sys == 16) {
		string hex;
		int whole = this->dec;
		int rest;

		const char HEX[]{ '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };
		do {
			rest = whole % 16;
			whole /= 16;

			hex = HEX[rest] + hex;
		} while (whole);

		this->number = hex;
		this->system = 16;
	}
	else if (this->system == 16 && sys == 10) {
		int dec = 0;

		const char HEX[]{ '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };

		for (int i = 0; i < number.length(); i++) {
			for (int j = 0; j < 16; j++) {
				if (number[number.length() - i - 1] == HEX[j]) {
					dec += j * pow(16, i);
					j = 16;
				}
			}
		}
		this->dec = dec;
		this->system = 10;
	}
	else if (this->system == 16 && sys == 2) {
		string bin;

		const char HEX[]{ '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };
		const string BIN[]{ "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111" };

		for (int i = 0; i < number.length(); i++) {
			for (int j = 0; j < 16; j++) {
				if (number[i] == HEX[j]) {
					bin += BIN[j];
					break;
				}
			}
		}
		while (bin[0] == '0' && bin.length() > 1) {
			bin.erase(0, 1);
		}

		this->number = bin;
		this->system = 2;
	}
}



void TIntNumber2::add(TIntNumber* addition) {
	this->changeSystem(10);
	addition->changeSystem(10);

	this->dec = this->dec + addition->getDec();

	this->changeSystem(2);
}
void TIntNumber16::add(TIntNumber* addition) {
	this->changeSystem(10);
	addition->changeSystem(10);

	this->dec = this->dec + addition->getDec();

	this->changeSystem(16);
}


void TIntNumber::compare(TIntNumber* other) {

	if (this->dec == other->getDec()) {
		cout << this->dec << " == " << other->getDec();
	}
	else if (this->dec < other->getDec()) {
		cout << this->dec << " < " << other->getDec();
	}
	else {
		cout << this->dec << " > " << other->getDec();
	}
}