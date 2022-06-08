#pragma once

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

void writeInFile(const string& fileName);
void readOutFile(const string& fileName);
void genFile(const string& fileName, const string& newFileName);