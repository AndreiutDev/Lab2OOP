#include "rational.h"
#include "complex.h"
#include <stdio.h>

int  myCmmdc(int a, int b)
{
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}
rational::rational() {
	result.x = 1.0;
	result.y = 1.0;
}
void rational::rationalAdd(rationalNum R) {
	rationalNum temp;//ADD TWO RATIONAL NUMBERS
	temp.x = result.x;
	temp.y = result.y;
	result.x = result.x*R.y + result.y*R.x;
	result.y = result.y*R.y;
	printf(" %2d        %2d         %2d\n"  //OUTPUT
		"-----  +  -----   =  -----\n"
		" %2d        %2d         %2d\n", temp.x, R.x, result.x, temp.y, R.y, result.y);
	int cmmdc = myCmmdc(result.x, result.y);// simplify result
	result.x = result.x / cmmdc;
	result.y = result.y / cmmdc;
}

void  rational::rationalMul(rationalNum R)
{ 
	//MULTIPLIES THE RATIONAL NUMBERS
	rationalNum temp;
	temp.x = result.x;
	temp.y = result.y;
	result.x = result.x * R.x;
	result.y = result.y * R.y;
	int Cmmdc = myCmmdc(result.x, result.y);
	result.x = result.x / Cmmdc;
	result.y = result.y / Cmmdc;
	printf(" %2d        %2d         %2d \n"
		"-----  *  -----   =  -----\n"
		" %2d        %2d         %2d\n", temp.x, R.x, result.x, temp.y, R.y, result.y);
	int cmmdc = myCmmdc(result.x, result.y);// WE SIMPLIFY THE RESULT
	result.x = result.x / Cmmdc;
	result.y = result.y / Cmmdc;
}
void  rational::rationalQuot(rationalNum R)
{
	//DIVIDES THE RATIONAL NUMBERS, TREATED AS A REVERSED MULTIPLICATION
	rationalNum temp;
	temp.x = result.x;
	temp.y = result.y;
	result.x = result.x * R.y;
	result.y = result.y * R.x;
	printf(" %2d        %2d         %2d\n"
		"-----  /  -----   =  -----\n"
		" %2d        %2d         %2d\n", temp.x, R.x, result.x, temp.y, R.y, result.y);
	int Cmmdc = myCmmdc(result.x, result.y);//SIMPLIFY THE RESULT
	result.x = result.x / Cmmdc;
	result.y = result.y / Cmmdc;
}
int main(void)
{
	printf("=====================================\n");
	printf("=        RATIONAL TEST              =\n");
	printf("=====================================\n\n");
	rational m;

	rational::rationalNum r1; r1.x = 3; r1.y = 7;
	rational::rationalNum r2; r2.x = 6; r2.y = 9;
	rational::rationalNum r3; r3.x = 3; r3.y = 19;
	m.rationalAdd(r1);
	m.rationalMul(r2);
	m.rationalQuot(r3);
	printf("=====================================\n");
	printf("=        COMPLEX TEST               =\n");
	printf("=====================================\n\n");
	
	NumarComplex a = NumarComplex(3.0, 2.0);
	NumarComplex b = NumarComplex(3.0, -2.0);
	printf("a = %.1f + i(%.1f)\n", a.myComplexNumber.realPart, a.myComplexNumber.imaginaryPart);
	printf("b = %.1f + i(%.1f)\n", b.myComplexNumber.realPart, b.myComplexNumber.imaginaryPart);
	printf("\n#------------------#\n");
	printf("  /  SHOW_COMPL TEST /\n");
	printf("  #------------------#\n\n");
	//SHOW_COMPL() TEST
	a.show_compl();
	//SHOW_EXp() TEST
	printf("\n#------------------#\n");
	printf("  /  SHOW_EXP TEST   /\n");
	printf("  #------------------#\n\n");
	a.show_exp();
	//POLAR() TEST
	printf("\n#------------------#\n");
	printf("  /  POLAR           /\n");
	printf("  #------------------#\n\n");
	a.findPolarForm();
	//MULTIPLICATION TEST
	printf("\n#------------------#\n");
	printf("/  MUL TEST        /\n");
	printf("#------------------#\n\n");
	cNbr result1 = a.mul(b.myComplexNumber);
	printf("a x b = %.f + i(%.f)\n", result1.realPart, result1.imaginaryPart);
	//ADD TEST
	printf("\n#------------------#\n");
	printf("/ ADD TEST        /\n");
	printf("#------------------#\n\n");
	cNbr result2 = a.add(b.myComplexNumber);
	printf("a + b = %.f + i(%.f)\n", result2.realPart, result2.imaginaryPart);
	//DIV TEST
	printf("\n#------------------#\n");
	printf("/  DIV TEST        /\n");
	printf("#------------------#\n\n");
	cNbr result3 = a.quot(b.myComplexNumber);
	printf("a / b = %.f + i(%.f)\n\n", result3.realPart, result3.imaginaryPart);
	//WE CREATE AN ARRAY OF COMPLEX NUMBERS
	NumarComplex complexNumbers[5] = { NumarComplex(1.0, -1.0),
					   NumarComplex(1.5, -1.5),
					   NumarComplex(0.5, 1),
					   NumarComplex(1, 0.5),
					   NumarComplex(-1, -2) };
	printf("Creating the arry of complex numbers: \n");
	for (int i = 0; i < 5; i++)
		complexNumbers[i].show_compl();
	//SORT NACH DEM BETRAG
	int i, j;
	NumarComplex temp = NumarComplex(1, 1);
	for (i = 0; i < 5; i++)
		for (j = 0; j < 5; j++)
			if (complexNumbers[i].abs() > complexNumbers[j].abs())
			{
				temp = complexNumbers[i];
				complexNumbers[i] = complexNumbers[j];
				complexNumbers[j] = temp;
			}
	printf("The sorted numbers: \n");
	for (int i = 0; i < 5; i++)
		complexNumbers[i].show_compl();
	//THE SUM OF THE NUMBERS
	cNbr sum;
	sum.imaginaryPart = 0.0;
	sum.realPart = 0.0;
	for (int i = 0; i < 5; i++)
	{
		sum = complexNumbers[i].add(sum);
	}
	printf("The sum of the numbers = %.2f + i(%.2f)\n", sum.realPart, sum.imaginaryPart);

}