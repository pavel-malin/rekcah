#include<stdio.h>

int main()
{
	int int_var = 5;
	int *int_ptr;

	int_ptr = &int_var;  // address placenebt int_var to int_ptr
	printf("int_ptr = 0x%08x\n", int_ptr);
	printf("&int_ptr = 0x%08x\n", &int_ptr);
	printf("*int_ptr = 0x%08x\n", *int_ptr);

	printf("int_var is located at 0x%08x and contains the value %d\n", &int_var, int_var);
	printf("int_ptr is located at address 0x%08x, contains address 0x%08x and points to the value %d\n\n",
			&int_ptr, int_ptr, *int_ptr);
}
