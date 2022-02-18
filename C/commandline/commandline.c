#include<stdio.h>

int main(int arg_count, char *arg_list[])
{
	int i;
	printf("%d arguments were provided:\n", arg_count);
	for (i=0;i<arg_count;i++)
		printf("arguments #%d\t-\t%s\n", i, arg_list[i]);
}
