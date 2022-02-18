#include<stdio.h>

int main()
{
	int i;

	char char_array[5] = {'a', 'b', 'c', 'd', 'e'};
	int int_array[5] = {1, 2, 3, 4, 5};

	char *char_pointer;
	int *int_pointer;

	char_pointer = (char *) int_array;  // cast to type
	int_pointer = (int *) char_array;  // pointer data
			
	for (i=0;i<5;i++)	   // Character array integrations with int_pointer
	{
		printf("[integer pointer] points to the address %p containing the character '%c'\n", int_pointer, *int_pointer);
		int_pointer = (int *) ((char *) int_pointer + 1);
	}
	
	for (i=0;i<5;i++)	// Character array integrations with char_pointer
	{
		printf("[char pointer] pointer to the address %p containing the integer %d\n",
				char_pointer, *char_pointer);
		char_pointer = (char *) ((int *) char_pointer + 1);
	}
}

