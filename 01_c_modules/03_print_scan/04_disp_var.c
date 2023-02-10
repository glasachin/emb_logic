#include<stdio.h>
int main()
{
	int a = 123, b = 12345;
	long ax = 1234567890;
	short s = 4043;
	float x = 2.13459;
	double dx = 1.141597;
	char c = 'W';
	unsigned long ux = 2541567890;

	printf("%d,%d,%ld,%d,%f,%lf,%c,%u\n",a,b,ax,s,x,dx,c,ux);
	return 0;
}
