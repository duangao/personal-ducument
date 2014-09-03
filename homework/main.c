#include"add.h"

#include"bubblesort.h"
#include"printresult.h"
#define bool char
#define true 1
#define false 0
void main()
{
	int a[11],i;
	int b[11];
	printf("please input 10 datas: \n");
	for(i=1;i<=10;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	bool flag=true;
	while(flag==true)
	{
		printf("\n 1.bubblesort\n 2.sum \n 3.print sorted result \n 4.exit");
		printf("\n please choose the ordinal: ");
		int number=0;
		scanf("%d",&number);
		int sum=0;
		switch(number)
		{
			case 1:
				bubblesort(a,10);
				break;
			case 2:
				sum=add(a,10);
				printf("\n the sum of this array : %5d\n",sum);
				break;
			case 3:
				printArray(b,10,"\n origin array : ");
				printArray(a,10,"\n sorted array : ");
				break;
			case 4:
				flag=false;
				break;
			default:
				printf("please choose the correct ordinal!");
				break;
		}			
	}
}
