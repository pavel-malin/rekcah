#include<stdio.h>

int main()
{
	printf("Len type 'int' result\t\t %d byte\n", sizeof(int));
	printf("Len type 'unsigned int' result\t\t %d byte\n", sizeof(unsigned int));
	printf("Len type 'short int' result\t\t %d byte\n", sizeof(short int));
	printf("Len type 'long int' result\t\t %d byte\n", sizeof(long int));
	printf("Len type 'long long int' result\t\t %d byte\n", sizeof(long long int));
	printf("Len type 'float' result\t\t %d byte\n", sizeof(float));
	printf("Len type 'char' result\t\t %d byte\n", sizeof(char));
};
