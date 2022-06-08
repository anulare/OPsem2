#pragma once
#include "structs.h"

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cstdio>
#include <stdio.h>
#include <ctime>

using namespace std;

string toLower(string &str);



void writeInFile(const char* fileName);
void readOutFile(const char* fileName);

void writeInVector(const char* fileName, vector<ampula>& ampuls);

void del(const char* fileName, vector<ampula>& ampuls);

void warning(vector<ampula>& ampuls);