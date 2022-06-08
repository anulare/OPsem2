#include "pch.h"

void writeInFile(const string& fileName) {
    int answer;
    cout << "What do you want?\n\t(1)create a new file or\n\t(2)add to an existing file\n";
    cin >> answer;

    ofstream inFile;
    do {
        if (answer == 1) {
            inFile.open(fileName);
        } else if (answer == 2) {
            inFile.open(fileName, ios::app);
        } else {
            cout << "Invalid response, please try again: ";
            cin >> answer;
        }
    } while (answer!=1 && answer!=2);

    string str;

    if (!inFile.is_open()) {
        cout << fileName << " cannot be opened\n";
    }
    else {
        cout << ">>> " << fileName << " to WRITE was opened successfully\n\n";
        cout << "--Now enter your strings. Press Ctrl+Q+ENTER to stop writing text\n";
        cin.ignore();

        getline(cin, str, char(17));
        inFile << str << '\n';

        inFile.close();
        cout << "<<< " << fileName << " was closed successfully\n\n";
    }
}

void readOutFile(const string& fileName) {
    ifstream outFile(fileName);
    string str;

    if (!outFile.is_open()) {
        cout << fileName << " cannot be opened\n";
    }
    else {
        cout << ">>> " << fileName << " to READ was opened successfully\n";
        while (!outFile.eof()) {
            getline(outFile, str);
            cout << str << "\n";
        }

        outFile.close();
        cout << "<<< " << fileName << " was closed successfully\n\n";
    }
}

void genFile(const string& fileName, const string& newFileName) {
    ofstream inNewFile(newFileName);
    ifstream outFile(fileName);
    string str;
    int stringNumber = -1;

    if (!inNewFile.is_open() || !outFile.is_open()) {
        cout << fileName << " or " << newFileName << " cannot be opened\n";
    }
    else {
        while (!outFile.eof()) {
            stringNumber++;

            getline(outFile, str);
            inNewFile << stringNumber << ", " << str << ", " << str.length() << '\n';
        }
        outFile.close();
        inNewFile.close();
        cout << newFileName << " was generated successfully\n\n";
    }
}