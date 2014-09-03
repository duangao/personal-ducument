#include"printresult.h"
void printArray(int s[],int n,char* str)
{
	printf("%s",str);
	int i;
	for(i=1;i<11;i++)
	{
		printf("%5d",s[i]);
	}
	printf("\n");
}
