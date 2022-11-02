#include<stdio.h>
int main()
{
	int i1,i2,i3,i4,i5;
	int high =-32564, pos = 0;
	printf("Enter 5 integers: ");
	scanf("%d%d%d%d%d",&i1,&i2,&i3,&i4,&i5);
	pos += i1>high?1:0;
	high = i1>high?i1:high;
	pos += i2>high?1:0;
	high = i2>high?i2:high;
	pos += i3>high?1:0;
	high = i3>high?i3:high;
	pos += i4>high?1:0;
	high = i4>high?i4:high;
	pos += i5>high?1:0;
	high = i5>high?i5:high;
	printf("Highest Value: %d\n",high);
	printf("Position: %d\n", pos);
	return 0;

}
