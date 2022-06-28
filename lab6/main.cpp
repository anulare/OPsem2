#include "pch.h"

int main() {
    double a, b, c, d;
    MyTree y1;  //головне дерево
    MyTree y2;  //перше піддерево
    MyTree y3;  //друге піддерево

    cout << "Input variables:\n";
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "c = "; cin >> c;
    cout << "d = "; cin >> d;
    cout << '\n';

    y3.root = y3.createNode('+');   
    y3.connectLeft( y3.createNode('a') );
    y3.connectRight( y3.createNode('b') );

    y2.root = y2.createNode('/');
    y2.connectLeft(y3.root);
    y2.connectRight(y2.createNode('c'));

    y1.root = y1.createNode('*');
    y1.connectLeft(y2.root);
    y1.connectRight(y1.createNode('d'));

    y1.setValue(a,'a');
    y1.setValue(b,'b');
    y1.setValue(c,'c');
    y1.setValue(d,'d');

    y1.calculate();

    cout << "\n\n      *\n";
    cout << "    /   d\n";
    cout << "  +   c\n";
    cout << "a   b\n\n";

    y3.printSubtree();
    y2.printSubtree();
    y1.printSubtree();
}