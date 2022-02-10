#include<stdio.h>
#include<string.h>

int main()
{
	char str_a[20];  // Symbolic array of 20 elements
	char *pointer;  // Pointer for array of characters
	char *pointer2; // And another pointer
	
	strcpy(str_a, "Hello, world!\n");
	pointer = str_a;  // Put the first pointer at the beginning the array
	
	printf(pointer);

	pointer2 = pointer + 2; // Put the second pointer on 2 bytes,
	printf(pointer2);     // then display the content
	strcpy(pointer2, "Y you guys!\n");  // Copying to this palce
	printf(pointer);  // Display

};
