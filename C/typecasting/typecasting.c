#include<stdio.h>

int main()
{
	int a, b;
	float c, d;

	a = 13;
	b = 5;

	c = a/b;  // integer division
	d = (float) a / (float) b; // division of integers from floats
	
	printf("[integers]\t a = %d\t b = %d\n", a, b);
	printf("[float]\t a c = %f\t d = %f\n", c, d);
}
