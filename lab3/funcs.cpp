#include "class.h"

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
	str = buffer;
	return str;
}

void setAttributes(arithmeticProg& name) {
	name.setA();
	name.setD();
	name.setN();
}

arithmeticProg* genArray(int& size) {
	arithmeticProg* arr;
	arithmeticProg ap0;
	vector<arithmeticProg> vec;

	string str;
	while (toLower(str)!="no") {

		if (str == "yes" || str == "") {
			setAttributes(ap0);
			vec.push_back(ap0);

			cout << "\nDo you want to add more? -";
			cin >> str;
			cout << '\n';
		} else {
			cout << "\nInvalid response, try again please -";
			cin >> str;
			cout << '\n';
		}
	}
	cout << "\n\n\n";

	arr = new arithmeticProg[vec.size()];
	for (int i = 0; i < vec.size(); i++) {
		arr[i] = vec[i];
	}

	size = vec.size();
	return arr;
}

void outProgression(arithmeticProg prog) {
	cout << "[ ";
	for (int i = 0; i < prog.getN(); i++) {
		cout << prog.getA() + prog.getD() * i << " ";
	}
	cout << "]\n";
}

int findBiggestSum(arithmeticProg* arr, int size) {
	int max = 0;
	for (int i = 0; i < size; i++) {
		cout << i << " Sum = " << arr[i].getSum() << "\n";
		outProgression(arr[i]);
		if (arr[i].getSum()>arr[max].getSum()) {
			max = i;
		}
	}
	cout << '\n' << max << " progression has the biggest sum\n";
	return max;
}