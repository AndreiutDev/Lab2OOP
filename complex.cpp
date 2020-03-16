#include "complex.h"

double NumarComplex::getReal()const {	//get real
	return Real;
}

void NumarComplex::setReal(double realnou) {	//set real
	Real = realnou;
}
NumarComplex::NumarComplex(double real, double imaginar) {	//constructor
	Real = real;
	Imaginar = imaginar;

}