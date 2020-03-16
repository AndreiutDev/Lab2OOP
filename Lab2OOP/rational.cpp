#include "rational.h"
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
	rationalNum temp;
	temp.x = result.x;
	temp.y = result.y;
	result.x = result.x*R.y + result.y*R.x;
	result.y = result.y*R.y;
	printf(" %2d        %2d         %2d\n"
		"-----  +  -----   =  -----\n"
		" %2d        %2d         %2d\n", temp.x, R.x, result.x, temp.y, R.y, result.y);
	int cmmdc = myCmmdc(result.x, result.y);
	result.x = result.x / cmmdc;
	result.y = result.y / cmmdc;
}

void  rational::rationalMul(rationalNum R)
{
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
	int cmmdc = myCmmdc(result.x, result.y);
	result.x = result.x / Cmmdc;
	result.y = result.y / Cmmdc;
}
void  rational::rationalQuot(rationalNum R)
{
	rationalNum temp;
	temp.x = result.x;
	temp.y = result.y;
	result.x = result.x * R.y;
	result.y = result.y * R.x;
	printf(" %2d        %2d         %2d\n"
		"-----  /  -----   =  -----\n"
		" %2d        %2d         %2d\n", temp.x, R.x, result.x, temp.y, R.y, result.y);
	int Cmmdc = myCmmdc(result.x, result.y);
	result.x = result.x / Cmmdc;
	result.y = result.y / Cmmdc;
}
int main(void)
{
	rational m;
	rational::rationalNum r1; r1.x = 3; r1.y = 7;
	rational::rationalNum r2; r2.x = 6; r2.y = 9;
	rational::rationalNum r3; r3.x = 3; r3.y = 19;
	m.rationalAdd(r1);
	m.rationalMul(r2);
	m.rationalQuot(r3);
	printf("Bastarca test\n");
}