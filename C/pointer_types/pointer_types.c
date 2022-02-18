#include<stdio.h>

int main()
{
	int i;
	char char_array[5] = {'a', 'b', 'c', 'd', 'e'};
	int int_array[5] = {1, 2, 3, 4, 5};

	char *char_pointer;
	int *int_pointer;

	char_pointer = char_array;
	int_pointer = int_array;

	for (i=0;i<5;i++) // Traversing an array of integers with a pointer int_pointer
			 {
				 printf("[integer pointer] pointer to address %p containing integer %d\n", int_pointer, *int_pointer);
				 int_pointer = int_pointer + 1;
			 }
	for (i=0;i<5;i++)  // Traversing an array of chaacters with a char_pointer
	{
		printf("[char pointer] pointer to address %p containing character '%c'\n", char_pointer, *char_pointer);
		char_pointer = char_pointer + 1;
	}
}
