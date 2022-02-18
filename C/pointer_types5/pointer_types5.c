#include<stdio.h>

int main()
{
	int i;

	char char_array[5] = {'a', 'b', 'c', 'd', 'e'};
	int  int_array[5] = {1, 2, 3, 4, 5};

	unsigned int hacky_nonpointer;
	
	hacky_nonpointer = (unsigned int) char_array;

	for (i=0;i<5;i++)  // character array traversal
	{
		printf("[hacky_nonpointer] points to the address %p containing the character '%c'\n", hacky_nonpointer, *((char *) hacky_nonpointer));
	hacky_nonpointer = hacky_nonpointer + sizeof(char);
	}
	
	for (i=0;i<5;i++) // traversing an annay of integers
	{
		printf("[hacky_nonpointer] points to the address %p containing the integer %d\n", hacky_nonpointer, *((int *) hacky_nonpointer));
		hacky_nonpointer = hacky_nonpointer + sizeof(int);
	}
}

