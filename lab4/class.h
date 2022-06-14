#pragma once
//////////////libraries

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
/////////////classes

class complx {
private:
	double p;
	double fi;
	double a;
	double b;
public:
	
	double getA();
	double getB();

	void alg();
	void ind();

	complx();
	complx(double p);
	complx(double p, double fi);

	complx& operator++();
	complx& operator++(int);
	complx operator+(complx);
};