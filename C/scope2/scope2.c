#include<stdio.h>

int j = 42;  // j - global value

void func3()
{
	int i = 11, j = 999; // j - local value func3()
	printf("\t\t\t[we in func3] i = %d\n", i, j);
}

void func2()
{
	int i = 7;
	printf("\t\t[we in func2] i = %d\n", i, j);
	printf("\t\t[we in func2] setting = 1337\n");
	j = 1337; // real in value j
	func3();
	printf("\t\t[back to func2] i = %d, j = %d\n", i, j);
}

void func1()
{
	int i = 5; 
	printf("\t[we in func1] i = %d, j = %d\n", i, j);
	func2();
	printf("\t[back to func1] i = %d, j = %d\n", i, j);
}

int main()
{
	int i = 3;
	printf("[we in main] i = %d, j = %d\n", i, j);
	func1();
	printf("[back to main] i = %d, j = %d\n", i, j);
}

