#include<stdio.h>
#include<stdlib.h>
void usage(char *program_name)
{
	printf("Usage: %s <message> <# of times to repeat\n", program_name);
	exit(1);
}

int main(int argc, char *argv[])
{
	int i, count;
	// if (argc < 3) // if there are less than 3 arguments, and 
	// 	usage(argv[0]); // meassage and exit the program
	count = atoi(argv[2]);  // convert the 2nd argument to an integer
	printf("Repeat %d times...\n", count);

	for (i=0;i<count;i++)
		printf("%3d - %s\n", i, argv[1]); // Displaying the 1st Argument
}
