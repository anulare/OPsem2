#pragma once

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class TIntNumber {
protected:
	int system;
	int dec;
	string number;
public:
	int getDec();
	string getNumber();

	virtual void changeSystem(int sys) = 0;

	virtual void add(TIntNumber* addition) = 0;

	void compare(TIntNumber* other);
};

class TIntNumber2 : public TIntNumber {
public:
	void changeSystem(int sys);

	void add(TIntNumber* addition);

	TIntNumber2();
	TIntNumber2(string number);
};

class TIntNumber16 : public TIntNumber {
public:
	void changeSystem(int sys);

	void add(TIntNumber* addition);

	TIntNumber16();
	TIntNumber16(string number);
};