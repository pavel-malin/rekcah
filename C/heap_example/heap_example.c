#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
	char *char_ptr; // Pointer to type char
	int *int_ptr; // Pointer to type int
	int mem_size;
	
	if (argc < 2) // It there no command line arguments,
		mem_size =50; // use the default value of 50
	else
		mem_size = atoi(argv[1]);
	printf("\t[+] %d bytes in the heap are allocated for variable char_ptr\n", mem_size);
	char_ptr = (char *) malloc(mem_size); // Allocate memory in the piece
	
	if (char_ptr == NULL) // Check for failure of the malloc() function
	{
		fprintf(stderr, "ERROR: unable to allocate memory on the heap.\n");
		exit(-1);
	}

	strcpy(char_ptr, "This memory is on the heap.");
	printf("\t[+] 12 bytes in the heap are allocated for variable int_ptr\n");
	int_ptr = (int *) malloc(12); // Heap memory is allocated again.
	
	if ( int_ptr == NULL) // Check for failure of the malloc() function
	{
		fprintf(stderr, " ERROR: unable to allocate memory on the heap.\n");
		exit(-1);
	}

	*int_ptr = 31337; // We put the value 31337 where the int_ptr points
	printf("int_ptr (%p) --> %d\n", int_ptr, *int_ptr);

	printf("\t[-] The memory occupied by char_ptr is freed..\n");
	free(char_ptr); // Freeing heap memory
	
	printf("\t[+] allocating another 15 bytes for char_ptr\n");
	char_ptr = (char *) malloc(15);  // Allocating more heap memory
	
	if (char_ptr == NULL)  // Error cheking, in case malloc() fails
	{
		fprintf(stderr, "ERROR: could not allocate heap memory.\n");
		exit(-1);
	}

	strcpy(char_ptr, "new memory");
	printf("char_ptr (%p) --> %s'\n", char_ptr, char_ptr);
	
	printf("\t[-] freeing int_ptr's heap memory...\n");
	free(int_ptr); // Freeing heap memory
	printf("\t[-] freeing char_ptr's heap memory...\n");
	free(char_ptr); // Freeing the other block of heap memory
}
	

