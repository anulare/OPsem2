#pragma once
#include "class.h"

string toLower(string& str);

void setAttributes(arithmeticProg& name);
arithmeticProg* genArray(int& size);

int findBiggestSum(arithmeticProg* arr, int size);

void outProgression(arithmeticProg prog);