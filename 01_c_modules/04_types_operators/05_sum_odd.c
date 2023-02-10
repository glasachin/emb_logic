#include<stdio.h>
int main()
{
	int i1,i2,i3,i4,i5;
	int sum = 0;
	printf("Enter 5 numbers: ");
	scanf("%d%d%d%d%d",&i1,&i2,&i3,&i4,&i5);
	sum += i1%2 ? i1:0;
	sum += i2%2 ? i2:0;
	sum += i3%2 ? i3:0;
	sum += i4%2 ? i4:0;
	sum += i5%2 ? i5:0;
	printf("Sum of entered odd numbers is: %d\n",sum);
	return 0;
}
