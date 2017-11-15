#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	char Array1[10];
	int ArrayHead = 0;
	strcat(Array1,"1");
	ArrayHead++;
	strcat(Array1,"2");
	ArrayHead++;
	strcat(Array1,"3");
	ArrayHead++;
	Array1[ArrayHead] = '\0';
	ArrayHead--;
	strcat(Array1,"4");
	ArrayHead++;
	strcat(Array1,"5");
	ArrayHead++;
	

	
	
	printf("%d\n",ArrayHead);
	
	for(int i = 0;i<10;i++)
		printf("%c",Array1[i]);
	TestMethod();
	
}

void TestMethod()
{
	printf("\nTestMethod has been run\n");
}