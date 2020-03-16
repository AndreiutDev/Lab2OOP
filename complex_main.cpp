// lab2_oop.cpp : This file contains the 'main' function. Program execution begins and ends there.
///

#include <iostream>
#include "complex.h"

using namespace std;

NumarComplex add(NumarComplex c1, NumarComplex c2) {
    NumarComplex c3(0, 0);
    c3.setReal(c1.getReal() + c2.getReal());
    return c3;
}

int main()
{
    NumarComplex c1 = NumarComplex(1, 5);
    NumarComplex c2(17, -5);
    NumarComplex c3 = add(c1, c2);
    std::cout << c3.getReal();
}