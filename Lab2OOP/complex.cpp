#include "complex.h"
#include <stdio.h>
#include <math.h>

//1
NumarComplex::NumarComplex(double r, double i){
	myComplexNumber.imaginaryPart = i;
	myComplexNumber.realPart = r;
}
//2
//THE ADDITION
cNbr NumarComplex::add(cNbr other)
{ 
	cNbr complexReturn;
	complexReturn.imaginaryPart = myComplexNumber.imaginaryPart + other.imaginaryPart;
	complexReturn.realPart = myComplexNumber.realPart + other.realPart;
	return complexReturn;
}
//THE MULTIPLICATION
cNbr NumarComplex::mul(cNbr other)
{
	cNbr complexReturn;
	complexReturn.imaginaryPart = (-other.imaginaryPart* myComplexNumber.imaginaryPart + other.realPart * myComplexNumber.realPart);
	complexReturn.realPart = other.realPart*myComplexNumber.imaginaryPart + other.imaginaryPart*myComplexNumber.realPart;
	return complexReturn;
}

//THE DIVISION

cNbr NumarComplex::quot(cNbr other)
{
	cNbr complexReturn;
	complexReturn.imaginaryPart = (((myComplexNumber.realPart) * (other.realPart)) + ((myComplexNumber.imaginaryPart) * (other.imaginaryPart))) / (other.realPart*other.realPart + other.imaginaryPart*other.imaginaryPart);
	complexReturn.realPart = (((other.realPart) * (myComplexNumber.imaginaryPart)) - ((myComplexNumber.realPart) * (other.imaginaryPart))) / (other.realPart*other.realPart + other.imaginaryPart*other.imaginaryPart);
	return complexReturn;
}
//3
double  NumarComplex::abs()
{
	return (sqrt(myComplexNumber.imaginaryPart*myComplexNumber.imaginaryPart + myComplexNumber.realPart));
}
//4
void  NumarComplex::findPolarForm()
{
	double tg_alfa = atan(myComplexNumber.imaginaryPart/myComplexNumber.realPart);
	double radius = abs();
	printf("The polar form of the imaginary number - %.2f + i%.2f-  is : %.2f*(cos(%.2f) +isin(%.2f)", myComplexNumber.realPart, myComplexNumber.imaginaryPart, radius, tg_alfa, tg_alfa);
}
void NumarComplex::show_compl()
{
	printf("%.2f + i(%.2f) - Betrag: %.1f\n", myComplexNumber.realPart, myComplexNumber.imaginaryPart, abs());
}
void NumarComplex::show_exp()
{
	printf("Forma lui Euler a numarului complex este: e^i(%.2f +i(%.2f))\n", myComplexNumber.realPart, myComplexNumber.imaginaryPart);
}