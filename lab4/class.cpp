#include "pch.h"

double complx::getA() {
    return this->a = p*cos(fi);
}

double complx::getB() {
    return this->b = p*sin(fi);
}

void complx::alg() {
    if (this->b==0) {
        cout << "Algebraic form: " << this->a <<"\n";
    } else if (this->a==0) {
        cout << "Algebraic form: " << this->b << "i\n";
    } else if (this->b<0) {
        cout << "Algebraic form: " << this->a << " " << this->b << "i\n";
    } else {
        cout << "Algebraic form: " << this->a << " + " << this->b << "i\n";
    }
}

void complx::ind() {
    if (this->fi == 0) {
        cout << "Indicative form: " << this->p << "\n";
    }
    else {
        cout << "Indicative form: " << this->p << "*e^(" << this->fi << "i)\n";
    }
}


complx::complx() {
    this->a = 0;
    this->b = 0;
    this->p = 0;
    this->fi = 0;
}
complx::complx(double p) {
    this->p = p;
    this->fi = p*1.5;
    this->getA();
    this->getB();
}
complx::complx(double p, double fi) {
    this->p = p;
    this->fi = fi;
    this->getA();
    this->getB();
}



complx& complx::operator++() {
    this->a++;

    cout << "Prefix ++ increment (Re)\n";
    return *this;
};
complx& complx::operator++(int) {
    this->b++;

    cout << "Postfix ++ increment (Im)\n";
    return *this;
};
complx complx::operator+(complx obj) {
    complx temp;

    temp.a = this->a + obj.a;
    temp.b = this->b + obj.b;

    cout << "Sum\n";
    this->alg();
    cout << "+\n";
    obj.alg();
    cout << "=";

    return temp;
};