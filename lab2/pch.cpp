#include "pch.h"

string toLower(string& str) {
	string buffer;
	for (int i = 0; i < str.length(); i++) {
		if (isupper(str[i])) {
			buffer += tolower(str[i]);
		}
		else {
			buffer += str[i];
		}
	}
	return str = buffer;
}


void writeInVector(const char* fileName, vector<ampula>& ampuls) {
	ifstream outFile(fileName, ios::binary);
	ampula ampula0;

	while (outFile.read((char*)&ampula0, sizeof(ampula0))) {
		ampuls.push_back(ampula0);
	}
}

void writeInFile(const char* fileName) {

	int answer;
	cout << "What do you want?\n\t(1)create a new file or\n\t(2)add to an existing file\n";
	cin >> answer;

	ofstream inFile;
	do {
		if (answer == 1) {
			inFile.open(fileName, ios::binary);
		}
		else if (answer == 2) {
			inFile.open(fileName, ios::binary | ios::app);
		}
		else {
			cout << "Invalid response, please try again: ";
			cin >> answer;
		}
	} while (answer != 1 && answer != 2);
	
	ampula ampula0;
	string res;

	if (!inFile.is_open()) {
		cout << fileName << " cannot be opened\n";
	} else {
		cout << ">>> " << fileName << " to WRITE was opened successfully\n";
		cout << "  Input ampuls parameters:\n\n";

		while (toLower(res) != "no") {
			if (res == "yes" || res=="") {
				cout << "Name: ";
				cin >> ampula0.name;
				cout << "Date of production(DD MM YYYY) : ";
				cin >> ampula0.productionDay >> ampula0.productionMonth >> ampula0.productionYear;
				cout << "How long can be used after opening(HH:MM): ";
				cin >> ampula0.hoursAfterOpening;
				cin >> ampula0.minsAfterOpening;
				cout << "ShelfTime: ";
				cin >> ampula0.shelfTime;
				cout << "\n";

				inFile.write((char*)&ampula0, sizeof(ampula0));

				cout << "Do you want to add another ampula(yes or no)? -";
				cin >> res;
			} else{
				cout << "Invalid response, try again please -";
				cin >> res;
			}
		}
		inFile.close();
		cout << "\n<<< " << fileName << " was closed successfully\n\n\n";
	}
}

void readOutFile(const char* fileName) {
	ifstream outFile(fileName, ios::binary); 
	ampula ampula0;

	if (!outFile.is_open()) {
		cout << fileName << " cannot be opened\n";
	}
	else {
		cout << ">>> " << fileName << " to READ was opened successfully\n";	
		cout << "  Your ampuls: \n\n";
		while(outFile.read((char*)&ampula0, sizeof(ampula0))) {

			cout << "Name: " << ampula0.name << '\n';

			cout << "Date of production : ";
			cout.fill('0');
			cout.width(2);
			cout << ampula0.productionDay << ".";
			cout.fill('0');
			cout.width(2);
			cout << ampula0.productionMonth << ".";
			cout << ampula0.productionYear << "\n";

			cout << "How long can be used after opening(HH:MM): ";
			cout.fill('0');
			cout.width(2);
			cout << ampula0.hoursAfterOpening << ':';
			cout.fill('0');
			cout.width(2);
			cout << ampula0.minsAfterOpening << "\n";
			cout << "ShelfTime: " << ampula0.shelfTime << "\n\n";
		}
		cout << "<<< " << fileName << " was closed successfully\n\n\n";
	}
	outFile.close();
}

void del(const char* fileName, vector<ampula>& ampuls) {
	ofstream inFile(fileName, ios::binary);

	if (!inFile.is_open()) {
		cout << fileName << " cannot be opened\n";
	} else {
		for (int i = ampuls.size()-1; i >= 0; i--) {
			if (ampuls[i].shelfTime > 1) {
				ampuls.erase(ampuls.begin() + i);
			}
		}
		for (int i = 0; i < ampuls.size(); i++) {
			inFile.write((char*)&ampuls[i], sizeof(ampuls[i]));
		}
		cout << "----------------------------------------------\n";
		cout << "--ALL AMPULS WITH SHELFTIME > 1 WERE DELETED--\n";
		cout << "----------------------------------------------\n\n";
	}
	inFile.close();
}

void warning(vector<ampula>& ampuls) {
	int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

	int prodDay;
	int prodMonth;
	int prodYear;

	int shelfDays = 0;
	int daysPassed;
	int thisYear;

	int timeLeft;

	time_t ttime = time(0);
	tm* local_time = localtime(&ttime);

	for (int i = 0; i < ampuls.size(); i++) {
		prodDay = ampuls[i].productionDay;
		prodMonth = ampuls[i].productionMonth;
		prodYear = ampuls[i].productionYear;

		for (int j = 0; j < prodMonth - 1; j++) {
			prodDay += months[j];
		}
		thisYear = local_time->tm_year + 1900;

		shelfDays = round(ampuls[i].shelfTime * 365);
		daysPassed = -prodDay + (thisYear - prodYear) * 365 + local_time->tm_yday + 1;

		timeLeft = shelfDays - daysPassed;

		if (timeLeft <= 0) {
			cout << "!!! " << ampuls[i].name << " is expired!!!\n";
		} else if(timeLeft <= 10) {
			cout << "!!! " << ampuls[i].name << " is expiring in " << timeLeft << " days!!!\n";
		}
	}
	cout << '\n';
}