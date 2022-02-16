#include<stdio.h>
#include<string.h>

int main()
{
	char message[10];
	int count, i;
	
	strcpy(message, "Hello, world!");
	
	printf("How many times to repeat? ");
	scanf("%d", &count);

	for (i=0;i<count;i++)
		printf("%d - %s\n", i, message);
}
