#include<stdio.h>
#include<string.h>

int main() 
{
	char string[10];
	int A = -73;
	unsigned int B = 31337;
	strcpy(string, "sample");
	// output
	printf("[A] Dec: %d, Hex: %x, Unsigned: %u\n", A, A, A);
	printf("[B] Dec: %d, Hex: %x, Unsigned: %u\n", B, B, B);
	printf("[Field width at B] 3: '%3u', 10: '%10u', '%08u'\n", B, B, B);
	printf("[string] %s address %08x\n", string, string);
	printf("value A to address: %08x\n", &A);
}
