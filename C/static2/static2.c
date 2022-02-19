#include<stdio.h>

void function() // An example of a function with its own context
{
	int var = 5;
	static int static_var = 5; // Static variable initialization
	
	printf("\t[we to function] var @ %p = %d\n", &var, var);
	printf("\t[we to function] static_var @ %p = %d\n", &static_var, static_var);
	var++; // Increment var by 1
	static_var++; // Increment static_var by 1
}

int main () // main function with its own context
{
	int i;
	static int static_var = 1337; // Another static variable
				      // in a different context
	for (i=0;i<5;i++) // 5 loop iterations
	{
		printf("[we to main] static_var @ %p = %d\n", &static_var, static_var);
		function(); // function call
	}
}
