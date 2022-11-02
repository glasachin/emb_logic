#include<stdio.h>
int main()
{
	int i1,i2,i3,i4,i5;
	int p_n = 0;
	int n_n = 0;
	printf("Enter some + and - numbers: ");
	scanf("%d%d%d%d%d",&i1,&i2,&i3,&i4,&i5);
	p_n += i1>0?1:0;
	n_n += i1<0?1:0;
	p_n += i2>0?1:0;
	n_n += i2<0?1:0;
	p_n += i3>0?1:0;
	n_n += i3<0?1:0;
	p_n += i4>0?1:0;
	n_n += i4<0?1:0;
	p_n += i5>0?1:0;
	n_n += i5<0?1:0;
	printf("Number of positive numbers: %d\n",p_n);
	printf("Number of negative numbers: %d\n",n_n);
	return 0;
}
