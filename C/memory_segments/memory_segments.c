#include<stdio.h>
#include<stdlib.h>

int global_var;
int global_initialized_var = 5;

void function()  // demonstration function
{
	int stack_var; // Main() has a variable with the same name
	
	printf("stack_var function at the address 0x%08x\n", &stack_var);
}

int main()
{
	int stack_var; // Same name as a variable in function
	static int static_initialized_var = 5;
	static int static_var;
	int *heap_var_ptr;

	heap_var_ptr = (int *) malloc(4);
	
	// These variables in the initialized data segment
	printf("global_initialized_var at the address 0x%08x\n", &global_initialized_var);
	printf("static_initialized_var at the address 0x%08x\n\n", &static_initialized_var);

	// These variables in the unitialized data segment
	printf("static_var at the address 0x%08x\n", &static_var);
	printf("global_var at the address 0x%08x\n\n", &global_var);

	// This variable is in the pile
	printf("heap_var at the address 0x%08x\n\n", heap_var_ptr);

	// These variables in the stack
	printf("stack_var at the address 0x%08x\n", &stack_var);
	function();
}
