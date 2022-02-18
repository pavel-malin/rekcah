#include<stdio.h>

int main()
{
	int i;
	char char_array[5] = {'a', 'b', 'c', 'd', 'e'};
	int int_array[5] = {1, 2, 3, 4, 5};

	char *char_pointer;
	int *int_pointer;

	char_pointer = int_array;  // Now char_pointer and int_pointer
	int_pointer = char_array;  // point to incompatible data type
	
	for (i=0;i<5;i++)  // Traversing an array of integers with an int_pointer
	{
		printf("[integer pointer] pointer to the address %p containing the character '%c'\n",
				int_pointer, *int_pointer);
		int_pointer = int_pointer + 1;
	}

	for (i=0;i<5;i++) // Traversing an array of characters with a char_pointer
	{
		printf("[char pointer] points to the address %p containing the integer %d\n",
				char_pointer, *char_pointer);
		char_pointer = char_pointer + 1;
	}
}
