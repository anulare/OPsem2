#include "pch.h"

int main() {
    const string& fileName1 = "originalFile.txt";
    const string& fileName2 = "newFile.txt";

    writeInFile(fileName1);
    readOutFile(fileName1);

    genFile(fileName1, fileName2);
    readOutFile(fileName2);
    
}