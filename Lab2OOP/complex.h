#pragma once
typedef struct complex_number
{
	double imaginaryPart;
	double realPart;
}cNbr;
class NumarComplex
{
private:
	
public:
	cNbr myComplexNumber;
	NumarComplex(double r, double i);
	cNbr  add(cNbr x);
	cNbr  mul(cNbr x);
	cNbr  quot(cNbr x);
	double  abs();
	void  findPolarForm();
	void show_compl();
	void show_exp();
};

