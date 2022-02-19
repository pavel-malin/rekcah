#include<stdio.h>

int j = 42;  // global value

void func3()
{
	int i = 11, j = 999;  // here j - local value func3()
	printf("\t\t\t[we to func3] i @ 0x%08x = %d\n", &i, i);
	printf("\t\t\t[we to func3] j @ 0x%08x = %d\n", &j, j);
}

void func2()
{
	int i = 7;
	printf("\t\t[we to func2] i @ 0x%08x = %d\n", &i, i);
	printf("\t\t[we to func2] j @ 0x%08x = %d\n", &j, j);
	printf("\t\t[we to func2] setting j = 1337\n");
	j = 1337;  // read to value j
	func3();
	printf("\t\t[back to func2] i @ 0x%08x = %d\n", &i, i);
	printf("\t\t[back to func2] j @ 0x%08x = %d\n", &j, j);
}

void func1()
{
	int i = 5;
	printf("\t[we to func1] i @ 0x%08x = %d\n", &i, i);
	printf("\t[we to func1] j @ 0x%08x = %d\n", &j, j);
	func2();
	printf("\t[back to func1] i @ 0x%08x = %d\n", &i, i);
	printf("\t[back to func1] j @ 0x%08x = %d\n", &j, j);
}

int main()
{
	int i = 3;
	printf("[we to main] i @ 0x%08x = %d\n", &i, i);
	printf("[we to main] j @ 0x%08x = %d\n", &j, j);
	func1();
	printf("[back to main] i @ 0x%08x = %d\n", &i, i);
	printf("[back to main] j @ 0x%08x = %d\n", &j, j);
}
