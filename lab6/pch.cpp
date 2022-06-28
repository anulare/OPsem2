#include "pch.h"

Node* MyTree::createNode(char key){
	Node* newNode = new Node(key);

	return newNode;
}



void MyTree::connectLeft(Node* node){ 
	this->root->left = node;
}

void MyTree::connectRight(Node* node){
	this->root->right = node;
}





void MyTree::setValue(double value, char variableName){
	Node* node = this->findNode(variableName);
	
	node->value = value;
}

Node* MyTree::findNode(char key){
	return this->root->findNode(key);
}

double MyTree::calculate(){
	return this->root->calculate();
}

void MyTree::printSubtree() {
	cout << '\n';
	cout << "  " << this->root->key << '\n';
	cout << this->root->left->value << "   " << this->root->right->value;
	cout << '\n';
}


Node::Node(char key){
	this->left = nullptr;
	this->right = nullptr;

	this->key = key;
}

double Node::calculate() {
	switch (this->key) {
	case '+' :
		this->value = left->calculate() + right->calculate();
		cout << this->value << " = " << left->value << " + " << right->value << '\n';
		break;
	case '*' :
		this->value = left->calculate() * right->calculate();
		cout << this->value << " = " << left->value << " * " << right->value << '\n';
		break;
	case '/' :
		this->value = left->calculate() / right->calculate();
		cout << this->value << " = " << left->value << " / " << right->value << '\n';
		break;
	}

	return this->value;
}

Node* Node::findNode(char key) {
	if (this->key==key) {
		return this;
	}
	Node* tempNode = nullptr;
	if (left != nullptr) {
		tempNode = left->findNode(key);
		if (tempNode == nullptr && right != nullptr) {
			tempNode = right->findNode(key);
		}
	}
	return tempNode;
}