#include "pch.h"

int main() {
    int m, n;

    cout << "Input m: ";
    cin >> m;
    TIntNumber2* M = genArrBin(m);

    cout << "\nInput n: ";
    cin >> n;
    TIntNumber16* N = genArrHex(n);

    
    TIntNumber2 binSum = findSumBin(M,m);
    TIntNumber16 hexSum = findSumHex(N,n);

    hexSum.changeSystem(2);
    cout << "\nHex sum in binary form: " << hexSum.getNumber();
    cout << "\n\n";

    binSum.compare(&hexSum);

    delete[] M;
    delete[] N;

    system("pause>0");
}