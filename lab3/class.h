#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;


class arithmeticProg {

private:
	double a;
	double d;
	int n;
	double sum;

public:
	void setA();
	void setD();
	void setN();

	double getA();
	double getD();
	int getN();

	double getSum();
};