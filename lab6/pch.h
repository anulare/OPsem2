#pragma once

#include <iostream>
using namespace std;




struct Node {
	Node* left;		// лівий вузол
	Node* right;	// правий вузол

	char key;		// назва змінної або назва операції
	double value;	// значення змінної або значення результату

	Node(char key); // конструктор

	double calculate();
	Node* findNode(char key);
};


struct MyTree {
	Node* root;

	Node* createNode(char key);

	void connectLeft(Node* node);
	void connectRight(Node* node);

	void setValue(double value, char variableName);

	double calculate();

	void printSubtree();

private:
	Node* findNode(char key);
};