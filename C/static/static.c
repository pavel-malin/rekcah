#include<stdio.h>


void function() // An example of a function with its own context
{
	int var = 5;
	static int static_var = 5; // Static variable initialization
	
	printf("\t[we to function] var = %d\n", var);
	printf("\t[we to function] static_var = %d\n", static_var);
	var++; // Icrement var by 1
	static_var++; // Icrement static_var by 1
}

int main() // main function with its own context
{
	int i;
	static int static_var = 1337; // Another static variable
				      // in a different context
	for (i=0;i<5;i++)  // 5 loop iterations
	{
		printf("[we to main] static_var = %d\n", static_var);
		function(); // function call
	}
}
