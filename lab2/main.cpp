#include "pch.h"

int main(){
    const char* drugsFile1 = "drugs.bin";
    const char* drugsFile2 = "drugsEdit.bin";
    vector<ampula> ampuls;

    writeInFile(drugsFile1);
    readOutFile(drugsFile1);

    writeInVector(drugsFile1, ampuls);

    del(drugsFile2, ampuls);
    readOutFile(drugsFile2);

    warning(ampuls);

	system("pause>0");
}